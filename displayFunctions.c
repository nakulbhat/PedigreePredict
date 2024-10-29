
#define DISPLAY_FUNCTIONS_INCLUDED 1

#ifndef STRUCTS_INCLUDED
#include "structs.c"
#endif
#ifndef PERSON_FUNCTIONS_INCLUDED
#include "personFunctions.c"
#endif
#ifndef RELATION_FUNCTIONS_INCLUDED
#include "relationFunctions.c"
#endif

void displayPerson(Person *person)
{
    if (person == NULL)
    {
        printf("Person is NULL\n");
        return;
    }

    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Gender: %s\n", person->gender == MALE ? "Male" : "Female");
    printf("Characteristics: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", person->characteristics[i]);
    }
    printf("\n");

    if (person->relationOfOrigin != NULL)
    {
        char *father = person->relationOfOrigin->male->name;
        char *mother = person->relationOfOrigin->female->name;
        printf("Relation of Origin: Exists; Father: %s    Mother: %s\n", father, mother);
    }
    else
    {
        printf("Relation of Origin: NULL\n");
    }

    if (person->prevSibling != NULL)
    {
        printf("Previous Sibling: %s\n", person->prevSibling->name);
    }
    else
    {
        printf("Previous Sibling: NULL\n");
    }

    if (person->nextSibling != NULL)
    {
        printf("Next Sibling: %s\n", person->nextSibling->name);
    }
    else
    {
        printf("Next Sibling: NULL\n");
    }

    if (person->firstRelation != NULL)
    {
        char *spouse;
        if (person->gender == MALE)
            spouse = person->firstRelation->female->name;
        else
            spouse = person->firstRelation->male->name;
        printf("First Relation: Exists, Spouse: %s\n", spouse);
    }
    else
    {
        printf("First Relation: NULL\n");
    }
}

void displaySiblings(Person *person)
{
    printf("\n****Siblings of %s****\n", person->name);
    Relation *relOfOrigin = person->relationOfOrigin;
    Person *iterPerson = relOfOrigin->firstChild;
    while (iterPerson)
    {
        if (iterPerson != person)
            displayPerson(iterPerson);
        iterPerson = iterPerson->nextSibling;
    }
    printf("\n***********\n");
}

void displayChildren(Person *person)
{
    printf("\n****Children of %s****\n", person->name);
    if (person->firstRelation)
    {
        Relation *rels = person->firstRelation;
        while (rels)
        {
            Person *child = rels->firstChild;
            while (child)
            {
                displayPerson(child);
                child = child->nextSibling;
            }
            if (person->gender == MALE)
                rels = rels->maleNextRelation;
            else
                rels = rels->femaleNextRelation;
        }
    }
    else
    {
        printf("This person has no relationships or children");
    }
    printf("\n***********\n");
}

void displayCousins(Person *person)
{ // TODO
    Person *mother = person->relationOfOrigin->female;
    Person *father = person->relationOfOrigin->male;

    Person *motherSiblings = mother->relationOfOrigin->firstChild;
}
