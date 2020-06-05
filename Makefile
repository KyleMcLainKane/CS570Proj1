
#########################################
# Name: Kotaro Ueoka
# Username: cssc2138, (RedID 821442616)

# Name: Kyle McLain Kane
# Username: cssc2168, (RedID 820003555)

# Class: CS 570, Summer 2020
# Assignment information: Assignment #1 
# Filename: Makefile
#########################################

CXX = g++ -std=c++11 -pthread 
OBJS = main.o

bots: 	$(OBJS)
	$(CXX) -o bots $(OBJS)

main.o: main.cpp main.h
	$(CXX) -c main.cpp 

clean:
	rm -rf bots QUOTE.txt $(OBJS)
	
#################[EOF: Makefile]########
