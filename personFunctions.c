

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

#include "functionList.h"



personListNode *personListHead = NULL;

int generateID()
{
    static int count = 0;
    count++;
    return count;
}

Person *findPersonById(int id)
{
    personListNode *current = personListHead;
    while (current != NULL)
    {
        if (current->person->id == id)
            return current->person;
        else
            current = current->next;
    }
    return NULL;
}

void addPersonToList(Person *person)
{
    personListNode *newNode = (personListNode *)malloc(sizeof(personListNode));
    newNode->person = person;
    newNode->next = NULL;

    if (personListHead == NULL)
    {
        personListHead = newNode;
    }
    else
    {
        personListNode *current = personListHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

double *normaliseProbabilities(double *probabilities)
{
    double total = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        total += probabilities[i];
    }
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        probabilities[i] /= total;
    }
    return probabilities;
}

double *calculateProbabilities(double *a, double *b)
{
    double *probabilities = (double *)malloc(sizeof(double) * ARRAY_SIZE);
    probabilities[0] = ((a[0] * (4 * b[0] + 2 * b[1]) + a[1] * (2 * b[0] + 2 * b[1])) / 4);
    probabilities[1] = ((a[0] * (2 * b[1] + 4 * b[2]) + a[1] * (2 * (b[0] + b[1] + b[2])) + a[2] * (4 * b[0] + 2 * b[1])) / 4);
    probabilities[2] = ((a[1] * (b[1] + 2 * b[2]) + a[2] * (2 * b[1] + 4 * b[2])) / 4);

    return probabilities;
}

double *getProbabilities(Relation *relOfOrg)
{
    printf("Do you want to enter characteristics of the person?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        double *probabilities = (double *)malloc(sizeof(double) * ARRAY_SIZE);
        printf("Enter probabilities of the person having the following characteristics\n");
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            printf("Enter probability of characteristic %d\n", i + 1);
            scanf("%lf", &probabilities[i]);
        }
        return normaliseProbabilities(probabilities);
    }
    else if (relOfOrg == NULL)
    {
        double *probabilities = (double *)malloc(sizeof(double) * ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            probabilities[i] = 0.333;
        }
        return normaliseProbabilities(probabilities);
    }
    else
    {
        return normaliseProbabilities(calculateProbabilities(relOfOrg->male->characteristics, relOfOrg->female->characteristics));
}
}

Person *createPerson(Relation *relOfOrg, gender gender, char name[])
{
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->relationOfOrigin = relOfOrg;
    newPerson->id = generateID();
    strcpy(newPerson->name, name);
    newPerson->gender = gender;
    double *newPersonCharacteristics = getProbabilities(relOfOrg);
    memcpy(newPerson->characteristics, newPersonCharacteristics, sizeof(newPerson->characteristics));
    addPersonToList(newPerson);
    return newPerson;
}

Person *addChild(Relation *relOfOrg, gender gen, char name[])
{
    Person *newPerson = createPerson(relOfOrg, gen, name);

    Person *kid = relOfOrg->firstChild;

    if (kid == NULL)
        relOfOrg->firstChild = newPerson; // if no kids yet, then add as first kid
    // iterate until a kid has no nextSibling
    else
    {
        while (kid->nextSibling)
            kid = kid->nextSibling;
        newPerson->prevSibling = kid;
        kid->nextSibling = newPerson;
    }
    return newPerson;
}

void readPersonAndParents()
{
    char name[MAX_NAME_LENGTH];
    int gen;
    printf("Enter name of the person\n");
    scanf("%s", name);
    printf("Choose gender\n");
    printf("1. Male\n");
    printf("2. Female\n");
    scanf("%d", &gen);
    printf("Enter ID of father\n");
    int fatherID;
    scanf("%d", &fatherID);
    printf("Enter ID of mother\n");
    int motherID;
    scanf("%d", &motherID);
    Person *father = findPersonById(fatherID);
    Person *mother = findPersonById(motherID);
    Relation *marriage = findRelationById(fatherID, motherID);
    if (marriage == NULL)
    {
        marriage = addRelation(father, mother);
    }
    addChild(marriage, gen == 1 ? MALE :FEMALE, name);
}
