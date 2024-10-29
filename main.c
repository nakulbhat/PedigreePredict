#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCTS_INCLUDED
#include "structs.c"
#endif
#ifndef PERSON_FUNCTIONS_INCLUDED
#include "personFunctions.c"
#endif
#ifndef RELATION_FUNCTIONS_INCLUDED
#include "relationFunctions.c"
#endif
#include "displayFunctions.c"

Person *createPerson(Relation *relOfOrg, gender gender, char name[], int characteristics[]);
void addSibling(Relation *relOfOrg, gender gen, char name[], int characteristics[]);

void displayPerson(Person *person);
void displaySiblings(Person *person);
void displayChildren(Person *person);
// TODO: void displayCousins(Person *person);

void addRelation(Person *male, Person *female);

int main()
{
    int characteristics1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int characteristics2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Person *male = createPerson(NULL, MALE, "John", characteristics1);
    Person *female = createPerson(NULL, FEMALE, "Jane", characteristics2);

    addRelation(male, female);

    int characteristics3[10] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    addSibling(male->firstRelation, MALE, "Mike", characteristics3);
    addSibling(male->firstRelation, FEMALE, "Anna", characteristics3);

    displayPerson(male);
    displayPerson(female);
    displayPerson(male->firstRelation->firstChild);
    displayChildren(male);
    displaySiblings(male->firstRelation->firstChild);
    return 0;
}
