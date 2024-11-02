
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
        {
            currentRelationMale = currentRelationMale->maleNextRelation;
        }
        currentRelationMale->maleNextRelation = newRelation;
    }
    else
        male->firstRelation = newRelation;

    if (female->firstRelation != NULL)
    {
        Relation *currentRelationFemale = female->firstRelation;
        while (currentRelationFemale->femaleNextRelation)
        {
            currentRelationFemale = currentRelationFemale->femaleNextRelation;
        }
        currentRelationFemale->femaleNextRelation = newRelation;
    }
    else
    {
        female->firstRelation = newRelation;
    }
    return newRelation;
}

Relation *findRelationById(int maleId, int femaleId)
{
    Person *male = findPersonById(maleId);
    Person *female = findPersonById(femaleId);
    Relation *maleRelations = male->firstRelation;
    while (maleRelations)
    {
        if (maleRelations->female == female)
        {
            return maleRelations;
        }
        else
            maleRelations = maleRelations->maleNextRelation;
    }
    return NULL;
}
bool siblingExists(Person *person)
{
    return (person->nextSibling != NULL || person->prevSibling != NULL);
}

bool isSibling(Person *person1, Person *person2)
{
    if (siblingExists(person1) && siblingExists(person2))
    {
        return (person1->relationOfOrigin == person2->relationOfOrigin);
    }
    else
    {
        return false;
    }
}

bool isChild(Person *parent, Person *child)
{
    if (child->relationOfOrigin == NULL)
    {
        return false;
    }
    else
    {
        return (child->relationOfOrigin->male == parent || child->relationOfOrigin->female == parent);
    }
}

bool isCousin(Person *person1, Person *person2)
{
    Person *fatherSibling = NULL;
    Person *motherSibling = NULL;
    if (person1->relationOfOrigin && siblingExists(person1->relationOfOrigin->male))
    {
        fatherSibling = person1->relationOfOrigin->male->relationOfOrigin->firstChild;
        while (fatherSibling)
        {
            if (fatherSibling == person1->relationOfOrigin->male)
            {
                continue;
            }
            else
            {
                if (isChild(fatherSibling, person2))
                {
                    return true;
                }
            }
            fatherSibling = fatherSibling->nextSibling;
        }
    }
    if (person1->relationOfOrigin && siblingExists(person1->relationOfOrigin->female))
    {
        motherSibling = person1->relationOfOrigin->female->relationOfOrigin->firstChild;
        while (motherSibling)
        {
            if (motherSibling == person1->relationOfOrigin->female)
            {
                continue;
            }
            else
            {
                if (isChild(motherSibling, person2))
                {
                    return true;
                }
            }
            motherSibling = motherSibling->nextSibling;
        }
    }
    return false;
}

bool isPartner(Person *person1, Person *person2)
{
    return (findRelationById(person1->id, person2->id) != NULL);
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
    else if (isPartner(person1, person2))
    {
        return 3;
    }
    else if (isCousin(person1, person2))
    {
        return 4;
    }
    else
    {
        return 0;
    }
}
