
#ifndef STRUCTS
#define STRUCTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#define MAX_NAME_LENGTH 25
#define ARRAY_SIZE 3

typedef enum gender
{
    MALE,
    FEMALE
} gender;

typedef struct Person
{
    gender gender;
    char name[MAX_NAME_LENGTH];
    int id;
    struct Relation *relationOfOrigin;
    double characteristics[ARRAY_SIZE];
    struct Person *prevSibling;
    struct Person *nextSibling;
    struct Relation *firstRelation;
} Person;

typedef struct Relation
{
    struct Person *male;
    struct Person *female;
    struct Person *firstChild;
    int characteristics[20];
    struct Relation *maleNextRelation;
    struct Relation *femaleNextRelation;
} Relation;

typedef struct personListNode
{
    struct Person *person;
    struct personListNode *next;
} personListNode;

#endif