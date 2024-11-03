#include "../include/main.h"
#include "../include/displayFunctions.h"
#include "../include/structs.h"
#include "../include/inputFunctions.h"
#include "../include/menu.h"
#include "../include/personFunctions.h"
#include "../include/relationFunctions.h"

#include <assert.h>

void testPersonFunctions();
void testRelationFunctions();
void testDisplayFunctions();
void testMenu();

int main() {
    testPersonFunctions();
    testRelationFunctions();
    testDisplayFunctions();
    testMenu();
    return 0;
}

double sumProbabilities(double *probabilities) {
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += probabilities[i];
    }
    return sum;
}

void testPersonFunctions() {
    Person *person = createPerson(NULL, MALE, "test1", 1);
    assert(person->id == 1);
    assert(strcmp(person->name, "test1") == 0);
    assert(person->gender == MALE);
    assert(person->firstRelation == NULL);
    assert(person->nextSibling== NULL);
    assert(person->prevSibling == NULL);
    assert(sumProbabilities(person->characteristics) <= 1);
}

void testRelationFunctions() {
    Person *person1 = createPerson(NULL, MALE, "test2", 1);
    Person *person2 = createPerson(NULL, FEMALE, "test3", 1);
    Relation *relation = createRelation(person1, person2);
    assert (relation->male == person1);
    assert (relation->female == person2);
    assert (relation->firstChild == NULL);
    assert (relation->maleNextRelation == NULL);
    assert (relation->femaleNextRelation == NULL);
}

void testDisplayFunctions() {
    displayPerson(findPersonById(1));
}
void testMenu() {
    usePredefinedPedigree();
}