#define MENU_INCLUDED 1

#ifndef STRUCTS_INCLUDED
#include "structs.c"
#endif
#ifndef PERSON_FUNCTIONS_INCLUDED
#include "personFunctions.c"
#endif
#ifndef RELATION_FUNCTIONS_INCLUDED
#include "relationFunctions.c"
#endif
#ifndef DISPLAY_FUNCTIONS_INCLUDED
#include "displayFunctions.c"
#endif
#ifndef MENU_INCLUDED
#include "menu.c"
#endif

void usePredefinedPedigree()
{
    Person *paternalGrandfather = createPerson(NULL, MALE, "Paternal Grandfather");
    Person *paternalGrandmother = createPerson(NULL, FEMALE, "Paternal Grandmother");
    Person *maternalGrandfather = createPerson(NULL, MALE, "Maternal Grandfather");
    Person *maternalGrandmother = createPerson(NULL, FEMALE, "Maternal Grandmother");

    Relation *paternalMarriage = addRelation(paternalGrandfather, paternalGrandmother);
    Relation *maternalMarriage = addRelation(maternalGrandfather, maternalGrandmother);

    // Parents and their siblings
    Person *father = addChild(paternalMarriage, MALE, "Father");
    Person *fatherYoungerSister = addChild(paternalMarriage, FEMALE, "FatherYoungerSister");
    Person *motherOlderBrother = addChild(maternalMarriage, MALE, "MotherOlderBrother");
    Person *motherOlderSister = addChild(maternalMarriage, FEMALE, "MotherOlderSister");
    Person *fatherYoungerBrother = addChild(paternalMarriage, MALE, "FatherYoungerBrother");
    Person *mother = addChild(maternalMarriage, FEMALE, "Mother");

    // aunts and uncles
    Person *fatherYoungerSisterHusband = createPerson(NULL, MALE, "FatherYoungerSisterHusband");
    Person *motherOlderBrotherWife = createPerson(NULL, FEMALE, "MotherOlderBrotherWife");
    Person *motherOlderSisterHusband = createPerson(NULL, MALE, "MotherOlderSisterHusband");
    Person *fatherYoungerBrotherWife = createPerson(NULL, FEMALE, "FatherYoungerBrotherWife");

    Relation *parentsMarriage = addRelation(father, mother);
    Relation *fatherYoungerSisterMarriage = addRelation(fatherYoungerSisterHusband, fatherYoungerSister);
    Relation *motherOlderBrotherMarriage = addRelation(motherOlderBrotherWife, motherOlderBrother);
    Relation *motherOlderSisterMarriage = addRelation(motherOlderSisterHusband, motherOlderSister);
    Relation *fatherYoungerBrotherMarriage = addRelation(fatherYoungerBrotherWife, fatherYoungerBrother);

    // Children
    Person *child1 = addChild(parentsMarriage, MALE, "Child1");
    Person *child2 = addChild(parentsMarriage, FEMALE, "Child2");
    Person *child3 = addChild(parentsMarriage, MALE, "Child3");
    Person *child4 = addChild(parentsMarriage, FEMALE, "Child4");

    // Cousins from father's side
    Person *cousin1 = addChild(fatherYoungerSisterMarriage, MALE, "Cousin1");
    Person *cousin2 = addChild(fatherYoungerSisterMarriage, FEMALE, "Cousin2");
    Person *cousin3 = addChild(fatherYoungerBrotherMarriage, MALE, "Cousin3");
    Person *cousin4 = addChild(fatherYoungerBrotherMarriage, FEMALE, "Cousin4");

    // Cousins from mother's side
    Person *cousin5 = addChild(motherOlderBrotherMarriage, MALE, "Cousin5");
    Person *cousin6 = addChild(motherOlderBrotherMarriage, FEMALE, "Cousin6");
    Person *cousin7 = addChild(motherOlderSisterMarriage, MALE, "Cousin7");
    Person *cousin8 = addChild(motherOlderSisterMarriage, FEMALE, "Cousin8");

    printf("**Predefined Pedigree Loaded**\n");
}

void startMenu()
{
    printf("Enter your choice \n");
    int choice;
    gender newPersonGender;
    char newPersonName[MAX_NAME_LENGTH];
    while (choice)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            usePredefinedPedigree();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}