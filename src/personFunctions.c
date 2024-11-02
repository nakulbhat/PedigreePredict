#include "../include/relationFunctions.h"
#include "../include/inputFunctions.h"

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

