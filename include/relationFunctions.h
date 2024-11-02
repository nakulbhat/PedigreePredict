#ifndef RELTION_FUNCTIONS
#define RELTION_FUNCTIONS

#include "structs.h"

Relation *createRelation(Person*male, Person*female);
Relation *addRelation(Person *male, Person *female);
Relation* findRelationById(int fatherid, int motherid);
bool siblingExists(Person* person);
bool isSibling(Person *person1, Person *person2);
bool isChild(Person *parent, Person *child);
bool isCousin(Person *person1, Person *person2);
bool isPartner(Person *person1, Person *person2);
int getRelationType(Person *person1, Person *person2);
#endif