#include "main.h"


// Create file name "QUOTE.txt" in the current working directory
void createFile(){
    ofstream file("QUOTE.txt");  // Create file
    int processID = getpid();
    file << processID << "\r\n"; // pid followed by a Carriage Return and Newline
    file.close();
}



void* writeEvenQuote(void* arg) {
    for(int i=0; i<8;i++){ // Run total of 8 times
        
        pthread_t thId = pthread_self();
        

        sleep(2); // Run Evens every 2 seconds
        
        sem_wait(&FLAG); // Lock Semaphore
        
        cout << "Thread " << thId << " is running" << endl;

        ofstream file;
        file.open("QUOTE.txt", ios_base::app); // Append text to file
        string quote = "Controlling complexity is the essence of computer programming. --Brian Kernigan";
        file << thId << " " << quote << "\r\n"; // tid followed by a Carriage Return and Newline
        file.close();

        sem_post(&FLAG); // Release Semaphore

        
        
    }
   
    return 0;
}

void* writeOddQuote(void* arg) {
    for(int i=0; i<8;i++){

        sleep(3); // Run Odds every 3 seconds
        sem_wait(&FLAG); // Lock Semaphore
        pthread_t thId = pthread_self();
        cout << "Thread " << thId << " is running" << endl;
  

        ofstream file;
        file.open("QUOTE.txt", ios_base::app); // Append text to file
        string quote = "Computer science is no more about computers than astronomy is about telescopes. --Edsger Dijkstra";
        file << thId << " " << quote << "\r\n"; // pid followed by a Carriage Return and Newline
        file.close();

        sem_post(&FLAG); // Release Semaphore
        
    }
    return 0;
}




void runThreads() {
    sem_init(&FLAG, 0, 1); // Create semaphore
    
    int value;
    sem_getvalue(&FLAG, &value);
    
    
    pthread_t threads[THREAD_COUNT]; // Used to uniquely identify threads
    
    for(unsigned int i=0; i< THREAD_COUNT; i++){
        sem_wait(&FLAG); // Lock Semaphore
        if (i % 2==0){  // Even Threads 0,2,4,6
            pthread_create(&threads[i], NULL, writeEvenQuote, NULL);
        }
        else {  // Odd Threads 1,3,5
            pthread_create(&threads[i], NULL, writeOddQuote, NULL);
        }
        sem_post(&FLAG); // Release Semaphore
    }

    for(unsigned int i=0; i< THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }

    sem_destroy(&FLAG); // Destroy semaophore after finished using
    cout << "WE ARE DONE" << endl;
}



int main() {
    createFile();
    runThreads();

}
