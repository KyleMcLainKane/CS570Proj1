Team: GG NEXT

Name: Kotaro Ueoka
Username: cssc2138, (RedID 821442616)
Name: Kyle McLain Kane
Username: cssc2168, (RedID 820003555)

Class: CS 570, Summer S1 2020
Assignment information: Assignment #1
Filename: README

File manifest
- README.txt
- main.cpp
- main.h
- Makefile

Instructions:
- Once you are in the correct directory ~/a1 all that is needed is to follow the steps listed in compile instructions to get the proper output
- When you have finished following the compule sequence listed, then you may run bots (bots is our resulting executable)
	- What this will do is print out to the terminal what the current thread is and will display a finishing message when the program is done running
	- The resulting file created from this sequence will be called QUOTE.txt

Compile Instructions:
- make		(NOTE: has to be done in the file the code is in, and we compile using the g++ compiler)

Operating Instructions (In-order):
- make									(NOTE: This compiles our code)
- bots									(NOTE: This creates a executable where we can run bots and it creates the resulting QUOTE)
	- You will now have your own quote file

Significant Design Choices:
- We begin running the threads 2 seconds after we have started running the program. Our reason for doing this is to avoid threads running out of order, and 
  running before other threads have the chance to be initialized
- We implement the pthread.h, unistd.h, and the semaphore.h in order to do certain calls for our functions

Known deficiencies or bugs:
- We had some wierd timing bugs however they appear to be fixed with our implementation of a buffer system that prevents threads being created and run at the same time

Lessons Learned:
- We learned how to use the pthread calls
- How to create and manage semaphores
- More C++
- How to work as a duo well
- Effective communication skills
- How semaphores work
- How threading works, and how we can view where it is
- How to get a process ID
- How sem_init, sem_getvalue, sem_post, sem_wait, and sem_destroy work
- How to have more complex makefiles
- How to initialize and use a semaphore

Explanation of process:
For this project we met a few times to plan and write the code together. We also used our meetings in order to work through issues that we were having. In this program
we start by creating our file QUOTE that we will be writing to. In this function wewrite our process ID and close the file. We then decided to have a small 2 second buffer 
in the beginning where we create our threads. Once all our threads were created we began to run through the threads, as we split them up into two distinct functions based
whether or not it was an odd time or an even time. Once split, we then open up the QUOTE.txt and write the thread id followed by its appropriate quote. Meanwhile we write
to the console the current thread running at the time. Once complete we close the QUOTE.txt at the appropriate time, while modifying the semaphore FLAG. Once completed with our
8 pass throughs we exit gracefully. 