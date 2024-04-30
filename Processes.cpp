//
//  Processes.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//

/*
 @file Processes.cpp
 @author Diego Lopez
 @description: Explore and use functions related to process creation & handling
 in Unix-based OSs
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"

using namespace std;

// Part 1: Working With Process IDs
pid_t getProcessID(void) {
  // TODO: Add your code here
  return getpid(); // Find and return processID
}

// Part 2: Working With Multiple Processes
string createNewProcess(void) {
  pid_t id = fork();

  // DO NOT CHANGE THIS LINE OF CODE
  process_id = id;

  if (id == -1) {
    return "Error creating process";
  } else if (id == 0) {
    // TODO: Add your code here
    cout << "I am a child process!" << endl; // Print message

    // Return string (null character represents end of string)
    return "I am bored of my parent, switching programs now\0";
  } else {
    // TODO: Add your code here
    cout << "I just became a parent!" << endl; // Print message
    wait(NULL); // Wait for child process to finish

    // Return string (null character represents end of string)
    return "My child process just terminated!\0";
  }
}

// Part 3: Working With External Commands"
void replaceProcess(char *args[]) {
  // Spawn a process to execute the user's command.
  pid_t id = fork();

  // TODO: Add your code here
  if (id == 0) {
    // Change child memory image to a different program by passing arguments to
    // execvp function, soruce: http://linux.die.net/man/3/execvp
    execvp(args[0], args);
  } else {
    wait(NULL); // Make parent wait for child process to terminate
  }
}

#endif /* TestProg_cpp */
