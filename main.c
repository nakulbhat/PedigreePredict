
#ifndef STRUCTS_INCLUDED
#include "structs.c"
#endif
#ifndef PERSON_FUNCTIONS_INCLUDED
#include "personFunctions.c"
#endif
#ifndef RELATION_FUNCTIONS_INCLUDED
#include "relationFunctions.c"
#endif
#include "displayFunctions.c"

Person *createPerson(Relation *relOfOrg, gender gender, char name[], int characteristics[]);
Person* addChild(Relation *relOfOrg, gender gen, char name[], int characteristics[]);

void displayPerson(Person *person);
void displaySiblings(Person *person);
void displayChildren(Person *person);
void displayCousins(Person *person);

Relation *addRelation(Person *male, Person *female);

int main(){
int characteristics1[3] = {1, 2, 3};
int characteristics2[3] = {10, 9, 8};
int characteristics3[3] = {1, 3, 5};
int characteristics4[3] = {10, 8, 6};

    // Grandparents
    Person *paternalGrandfather = createPerson(NULL, MALE, "Paternal Grandfather", characteristics1);
    Person *paternalGrandmother = createPerson(NULL, FEMALE, "Paternal Grandmother", characteristics2);
    Person *maternalGrandfather = createPerson(NULL, MALE, "Maternal Grandfather", characteristics3);
    Person *maternalGrandmother = createPerson(NULL, FEMALE, "Maternal Grandmother", characteristics4);

    Relation *paternalMarriage = addRelation(paternalGrandfather, paternalGrandmother);
    Relation *maternalMarriage = addRelation(maternalGrandfather, maternalGrandmother);

    // Parents and their siblings
    Person* father = addChild(paternalMarriage, MALE, "Father", characteristics1);
    Person* fatherYoungerSister = addChild(paternalMarriage, FEMALE, "FatherYoungerSister", characteristics2);
    Person* motherOlderBrother = addChild(maternalMarriage, MALE, "MotherOlderBrother", characteristics3);
    Person* motherOlderSister = addChild(maternalMarriage, FEMALE, "MotherOlderSister", characteristics4);
    Person* fatherYoungerBrother = addChild(paternalMarriage, MALE, "FatherYoungerBrother", characteristics1);
    Person* mother = addChild(maternalMarriage, FEMALE, "Mother", characteristics2);

    // aunts and uncles
    Person* fatherYoungerSisterHusband = createPerson(NULL, MALE, "FatherYoungerSisterHusband", characteristics3);
    Person* motherOlderBrotherWife = createPerson(NULL, FEMALE, "MotherOlderBrotherWife", characteristics4);
    Person* motherOlderSisterHusband = createPerson(NULL, MALE, "MotherOlderSisterHusband", characteristics1);
    Person* fatherYoungerBrotherWife = createPerson(NULL, FEMALE, "FatherYoungerBrotherWife", characteristics2);

    Relation* parentsMarriage = addRelation(father, mother);
    Relation* fatherYoungerSisterMarriage = addRelation(fatherYoungerSisterHusband, fatherYoungerSister);
    Relation* motherOlderBrotherMarriage = addRelation(motherOlderBrotherWife, motherOlderBrother);
    Relation* motherOlderSisterMarriage = addRelation(motherOlderSisterHusband, motherOlderSister);
    Relation* fatherYoungerBrotherMarriage = addRelation(fatherYoungerBrotherWife, fatherYoungerBrother);

    // Display family members
    displayPerson(father);
    displayPerson(mother);
    displayPerson(fatherYoungerSister);
    displayPerson(fatherYoungerSisterHusband);
    displayPerson(motherOlderBrother);
    displayPerson(motherOlderBrotherWife);
    displayPerson(motherOlderSister);
    displayPerson(motherOlderSisterHusband);
    displayPerson(fatherYoungerBrother);
    displayPerson(fatherYoungerBrotherWife);

    // Children
    Person* child1 = addChild(parentsMarriage, MALE, "Child1", characteristics1);
    Person* child2 = addChild(parentsMarriage, FEMALE, "Child2", characteristics2);
    Person* child3 = addChild(parentsMarriage, MALE, "Child3", characteristics3);
    Person* child4 = addChild(parentsMarriage, FEMALE, "Child4", characteristics4);

    // Cousins from father's side
    Person* cousin1 = addChild(fatherYoungerSisterMarriage, MALE, "Cousin1", characteristics1);
    Person* cousin2 = addChild(fatherYoungerSisterMarriage, FEMALE, "Cousin2", characteristics2);
    Person* cousin3 = addChild(fatherYoungerBrotherMarriage, MALE, "Cousin3", characteristics3);
    Person* cousin4 = addChild(fatherYoungerBrotherMarriage, FEMALE, "Cousin4", characteristics4);

    // Cousins from mother's side
    Person* cousin5 = addChild(motherOlderBrotherMarriage, MALE, "Cousin5", characteristics1);
    Person* cousin6 = addChild(motherOlderBrotherMarriage, FEMALE, "Cousin6", characteristics2);
    Person* cousin7 = addChild(motherOlderSisterMarriage, MALE, "Cousin7", characteristics3);
    Person* cousin8 = addChild(motherOlderSisterMarriage, FEMALE, "Cousin8", characteristics4);

    // Display children
    displayPerson(child1);
    displayPerson(child2);
    displayPerson(child3);
    displayPerson(child4);

    // Display cousins
    displayPerson(cousin1);
    displayPerson(cousin2);
    displayPerson(cousin3);
    displayPerson(cousin4);
    displayPerson(cousin5);
    displayPerson(cousin6);
    displayPerson(cousin7);
    displayPerson(cousin8);
    displayCousins(child1);

    return 0;
}
