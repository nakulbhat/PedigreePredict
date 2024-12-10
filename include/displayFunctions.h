
#ifndef DISPLAY_FUNCTIONS
#define DISPLAY_FUNCTIONS

#include "structs.h"


#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void clearScreen();
void displayPerson(Person *person);
void displaySiblings(Person *person);
void displayChildren(Person *person);
void displayCousins(Person *person);
void displayPersonBrief(Person *person);
void displayPersonList();
void displayPersonById(int id);

#endif