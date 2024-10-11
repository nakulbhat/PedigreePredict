#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 25

typedef enum gender
{
    MALE,
    FEMALE
} gender;

typedef struct Person
{
    gender gender;
    char name[MAX_NAME_LENGTH];
    int id;
    struct Relation *relationOfOrigin;
    int characteristics[10];
    struct Person *prevSibling;
    struct Person *nextSibling;
    struct Relation *firstRelation;
} Person;

typedef struct Relation
{
    struct Person *male;
    struct Person *female;
    struct Person *firstChild;
    int characteristics[20];
    struct Relation *maleNextRelation;
    struct Relation *femaleNextRelation;
} Relation;

Person *createPerson(Relation *relOfOrg, gender gender, char name[], int characteristics[]);
void addSibling(Relation *relOfOrg, gender gen, char name[], int characteristics[]);
Relation *createRelation(Person *male, Person *female);
void addRelation(Person *male, Person *female);
void displayPerson(Person *person);

int main()
{
    int characteristics1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int characteristics2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Person *male = createPerson(NULL, MALE, "John", characteristics1);
    Person *female = createPerson(NULL, FEMALE, "Jane", characteristics2);

    addRelation(male, female);

    int characteristics3[10] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    addSibling(male->firstRelation, MALE, "Mike", characteristics3);
    addSibling(male->firstRelation, FEMALE, "Anna", characteristics3);

    displayPerson(male);
    displayPerson(female);
    displayPerson(male->firstRelation->firstChild);
    displayPerson(male->firstRelation->firstChild->nextSibling);
    return 0;
}


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

Relation *createRelation(Person *male, Person *female)
{
    Relation *newRelation = (Relation *)malloc(sizeof(Relation));
    newRelation->male = male;
    newRelation->female = female;
    return newRelation;
}

void addRelation(Person *male, Person *female)
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
}

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
        char* father = person->relationOfOrigin->male->name;
        char* mother = person->relationOfOrigin->female->name;
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

