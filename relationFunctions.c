
#define RELATION_FUNCTIONS_INCLUDED 1

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

Relation *createRelation(Person *male, Person *female)
{
    Relation *newRelation = (Relation *)malloc(sizeof(Relation));
    newRelation->male = male;
    newRelation->female = female;
    return newRelation;
}

Relation *addRelation(Person *male, Person *female)
{
    Relation *newRelation = createRelation(male, female);

    if (male->firstRelation != NULL)
    {
        Relation *currentRelationMale = male->firstRelation;
        while (currentRelationMale->maleNextRelation)
            currentRelationMale = currentRelationMale->maleNextRelation;
        currentRelationMale->maleNextRelation = newRelation;
    }
    else
        male->firstRelation = newRelation;

    if (female->firstRelation != NULL)
    {
        Relation *currentRelationFemale = female->firstRelation;
        while (currentRelationFemale->femaleNextRelation)
            currentRelationFemale = currentRelationFemale->femaleNextRelation;
        currentRelationFemale->femaleNextRelation = newRelation;
    }
    else
        female->firstRelation = newRelation;
    return newRelation;
}

Relation *findRelationById(int fatherid, int motherid)
{
    Person *father = findPersonById(fatherid);
    Person *mother = findPersonById(motherid);
    Relation *currentRelation = father->firstRelation;
    while (currentRelation)
    {
        if (currentRelation->female == mother)
            return currentRelation;
        else
            currentRelation = currentRelation->maleNextRelation;
    }
    return NULL;
}

int isSibling(Person *person1, Person *person2)
{
    return (person1->relationOfOrigin == person2->relationOfOrigin);
}

int siblingExists(Person *person)
{
    return (person->nextSibling != NULL || person->prevSibling != NULL);
}

int isChild(Person *parent, Person *child)
{
    return (child->relationOfOrigin->male == parent || child->relationOfOrigin->female == parent);
}

int isCousin(Person *person1, Person *person2)
{
    Person *fatherSibling = NULL;
    Person *motherSibling = NULL;
    if (siblingExists(person1->relationOfOrigin->male))
    {
        fatherSibling = person1->relationOfOrigin->male->relationOfOrigin->firstChild;
        while (fatherSibling)
        {
            if (fatherSibling == person1->relationOfOrigin->male)
                continue;
            else
            {
                if (isChild(fatherSibling, person2))
                    return 1;
            }
        }
    }
    if (siblingExists(person1->relationOfOrigin->female))
    {
        motherSibling = person1->relationOfOrigin->female->relationOfOrigin->firstChild;
        while (motherSibling)
        {
            if (motherSibling == person1->relationOfOrigin->female)
                continue;
            else
            {
                if (isChild(motherSibling, person2))
                    ;
                return 1;
            }
        }
    }
    return 0;
}

int isPartner(Person *person1, Person *person2)
{
    return findRelationById(person1->id, person2->id) != NULL;
}

int getRelationType(Person *person1, Person *person2)
{
    if (isChild(person1, person2) || isChild(person2, person1))
    {
        return 1;
    }
    else if (isSibling(person1, person2))
    {
        return 2;
    }
    else if (isPartner(person1, person2)){
        return 3;
    }
    else if (isCousin(person1, person2)){
        return 4;
    }
    else return 0;
}
