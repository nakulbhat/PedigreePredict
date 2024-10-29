
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

int generateID()
{
    static int count = 0;
    count++;
    return count;
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

Person *createPerson(Relation *relOfOrg, gender gender, char name[])
{
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->relationOfOrigin = relOfOrg;
    newPerson->id = generateID();
    strcpy(newPerson->name, name);
    newPerson->gender = gender;
    double *newPersonCharacteristics = NULL;
    if (relOfOrg == NULL)
    {
        newPersonCharacteristics = (double *)malloc(sizeof(double) * ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            newPersonCharacteristics[i] = 0.333;
        }
    }
    else
    {
        newPersonCharacteristics = calculateProbabilities(relOfOrg->male->characteristics, relOfOrg->female->characteristics);
    }
    normaliseProbabilities(newPersonCharacteristics);

    memcpy(newPerson->characteristics, newPersonCharacteristics, sizeof(newPerson->characteristics));
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
