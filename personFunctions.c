

#define PERSON_FUNCTIONS_INCLUDED 1

#ifndef STRUCTS_INCLUDED
#include "structs.c"
#endif
#ifndef PERSON_FUNCTIONS_INCLUDED
#include "personFunctions.c"
#endif
#ifndef RELATION_FUNCTIONS_INCLUDED
#include "relationFunctions.c"
#endif
#ifndef INPUT_FUNCTIONS_INCLUDED
#include "inputFunctions.c"
#endif
#ifndef DISPLAY_FUNCTIONS_INCLUDED
#include "displayFunctions.c"
#endif
#ifndef MENU_INCLUDED
#include "menu.c"
#endif

#include "functionList.h"

int generateID()
{
    static int count = 0;
    count++;
    return count;
}

personListNode **getPersonListHead()
{
    static personListNode *personListHead = NULL;
    return &personListHead;
}

Person *findPersonById(int id)
{
    personListNode *current = *getPersonListHead();
    while (current != NULL)
    {
        if (current->person->id == id)
            {return current->person;}
        else
            {current = current->next;}
    }
    return NULL;
}

void addPersonToList(Person *person)
{
    personListNode **head = getPersonListHead();
    personListNode *newNode = (personListNode *)malloc(sizeof(personListNode));
    newNode->person = person;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        personListNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

Person *createPerson(Relation *relOfOrg, gender gender, char name[], bool bypassCharacteristicReading)
{
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->relationOfOrigin = relOfOrg;
    newPerson->id = generateID();
    strcpy(newPerson->name, name);
    newPerson->gender = gender;
    double *newPersonCharacteristics = getProbabilities(relOfOrg, bypassCharacteristicReading);
    memcpy(newPerson->characteristics, newPersonCharacteristics, sizeof(newPerson->characteristics));
    addPersonToList(newPerson);
    return newPerson;
}

Person *addChild(Relation *relOfOrg, gender gen, char name[], bool bypassCharacteristicReading)
{
    Person *newPerson = createPerson(relOfOrg, gen, name, bypassCharacteristicReading);
    Person *kid = relOfOrg->firstChild;
    if (kid == NULL)
        relOfOrg->firstChild = newPerson;
    else
    {
        while (kid->nextSibling)
            kid = kid->nextSibling;
        newPerson->prevSibling = kid;
        kid->nextSibling = newPerson;
    }
    return newPerson;
}

