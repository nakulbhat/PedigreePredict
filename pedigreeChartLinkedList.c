#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 25

typedef enum gender {MALE, FEMALE} gender;

typedef struct Person
{
    gender gender;
    char name[MAX_NAME_LENGTH];
    int id;
    struct Relation* relationOfOrigin;
    int characteristics[10];
    struct Person* prevSibling;
    struct Person* nextSibling;
    struct Relation* firstRelation;
}Person;

typedef struct Relation
{
    struct Person* male;
    struct Person* female;
    struct Person* firstChild;
    int characteristics[20];
    struct Relation* maleNextRelation;
    struct Relation* femaleNextRelation;
}Relation;

int generateID(){
    static int count = 0;
    count++;
    return count;
}

Person* createPerson(Relation* relOfOrg, gender gender, char name[] ,int characteristics[]){
    Person* newPerson = (Person*) malloc(sizeof(Person));
    newPerson->id = generateID();
    strcpy(newPerson->name, name);
    newPerson->gender = gender;
    memcpy(newPerson->characteristics, characteristics, sizeof(newPerson->characteristics));
    return &newPerson;
}

void addSibling(Relation* relOfOrg, gender gender, char name[] ,int characteristics[]){~
    Person* newPerson = createPerson(relOfOrg, gender, name, characteristics);

    Person* kid = relOfOrg->firstChild;

    if (kid == NULL) relOfOrg->firstChild = newPerson; // if no kids yet, then add as first kid
    //iterate until a kid has no nextSibling
    else {
        while (kid->nextSibling)
            kid = kid->nextSibling;
        
        kid->nextSibling = newPerson;
    }
}

Relation* createRelation(Person* male, Person* female){
    Relation* newRelation = (Relation*) malloc(sizeof(Relation));
    newRelation->male = male;
    newRelation->female = female;
    return &newRelation;
}

void addRelation(Person* male, Person* female){
    Relation* newRelation = createRelation(male, female);
    Relation* relationMale = male->firstRelation;
    Relation* relationFemale = female->firstRelation;

    //find latest relations of primary and secondary

    while (relationMale && relationMale->maleNextRelation)
        relationMale = relationMale->maleNextRelation;

    while (relationFemale && relationFemale->femaleNextRelation);
    
}


int main(){
    return 0;
}
