#ifndef PERSONFUNCTION
#define PERSONFUNCTION

#include "structs.h"

int generateID();
personListNode **getPersonListHead();
Person* findPersonById(int id);
void addPersonToList(Person *person);
Person *createPerson(Relation *relOfOrg, gender gender, char name[], bool bypassCharacteristicReading);
Person *addChild(Relation *relOfOrg, gender gen, char name[], bool bypassCharacteristicReading);

#endif