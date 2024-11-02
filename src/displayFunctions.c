#include "../include/personFunctions.h"
#include "../include/relationFunctions.h"

void displayPerson(Person *person)
{
    printf("\n");
    if (person == NULL)
    {
        printf("Person is NULL\n");
        return;
    }
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Gender: %s\n", person->gender == MALE ? "Male" : "Female");
    printf("Characteristics: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%2f ", person->characteristics[i]);
    }
    printf("\n");
    if (person->relationOfOrigin != NULL)
    {
        char *father = person->relationOfOrigin->male->name;
        char *mother = person->relationOfOrigin->female->name;
        printf("Relation of Origin: Exists;\n Father: %s    Mother: %s\n", father, mother);
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
            {
                rels = rels->maleNextRelation;
            }
            else
            {
                rels = rels->femaleNextRelation;
            }
        }
    }
    else
    {
        printf("This person has no relationships or children");
    }
    printf("\n***********\n");
}

void displayCousins(Person *person)
{
    printf("****Cousins of %s****", person->name);
    Person *mother = person->relationOfOrigin->female;
    Person *motherSiblings = NULL;
    Person *fatherSiblings = NULL;
    if (mother->relationOfOrigin)
        motherSiblings = mother->relationOfOrigin->firstChild;
    Person *father = person->relationOfOrigin->male;
    if (father->relationOfOrigin)
        fatherSiblings = father->relationOfOrigin->firstChild;

    while (motherSiblings)
    {
        if (motherSiblings != mother)
        {
            displayChildren(motherSiblings);
        }
        motherSiblings = motherSiblings->nextSibling;
    }

    while (fatherSiblings)
    {
        if (fatherSiblings != father)
        {
            displayChildren(fatherSiblings);
        }
        fatherSiblings = fatherSiblings->nextSibling;
    }
}

void displayPersonBrief(Person *person)
{
    printf("ID: %d\t", person->id);
    printf("Name: %s\n", person->name);
}

void displayPersonList()
{
    personListNode *current = *getPersonListHead();
    while (current != NULL)
    {
        displayPersonBrief(current->person);
        current = current->next;
    }
    if (!*getPersonListHead())
        printf("No persons have been created\n");
}

void displayPersonById(int id)
{
    displayPerson(findPersonById(id));
}