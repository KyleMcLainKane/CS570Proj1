//
//  main.h
//  Assignment 1
//
//  Created by Kotaro Ueoka on 6/4/20.
//  Copyright © 2020 Kotaro Ueoka. All rights reserved.
//

#ifndef main_h
#define main_h


#include <iostream>
#include <fstream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define THREAD_COUNT 7
sem_t FLAG;
using namespace std;

void createFile();
void* writeEvenQuote(void* arg);
void* writeOddQuote(void* arg);
void runThreads();

#endif /* main_h */
