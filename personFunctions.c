
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

Person *createPerson(Relation *relOfOrg, gender gender, char name[], int characteristics[])
{
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->relationOfOrigin = relOfOrg;
    newPerson->id = generateID();
    strcpy(newPerson->name, name);
    newPerson->gender = gender;
    memcpy(newPerson->characteristics, characteristics, sizeof(newPerson->characteristics));
    return newPerson;
}

void addSibling(Relation *relOfOrg, gender gen, char name[], int characteristics[])
{
    Person *newPerson = createPerson(relOfOrg, gen, name, characteristics);

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
}
