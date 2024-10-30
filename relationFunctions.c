
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

Relation* addRelation(Person *male, Person *female)
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

Relation* findRelationById(int fatherid, int motherid)
{
    Person* father = findPersonById(fatherid);
    Person* mother = findPersonById(motherid);
    Relation* currentRelation = father->firstRelation;
    while(currentRelation)
    {
        if(currentRelation->female == mother)
            return currentRelation;
        else
            currentRelation = currentRelation->maleNextRelation;
    }
    return NULL;
}