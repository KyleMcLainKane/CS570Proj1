//Team: GG NEXT
//Name: Kotaro Ueoka
//Username: cssc2138, (RedID 821442616)
//Name: Kyle McLain Kane
//Username: cssc2168, (RedID 820003555)
//Class: CS 570, Summer S1 2020
//Assignment information: Assignment #1
//Filename: main.h

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
