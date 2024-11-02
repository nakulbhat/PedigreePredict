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


void usePredefinedPedigree()
{
    Person *paternalGrandfather = createPerson(NULL, MALE, "Paternal Grandfather", 1);
    Person *paternalGrandmother = createPerson(NULL, FEMALE, "Paternal Grandmother", 1);
    Person *maternalGrandfather = createPerson(NULL, MALE, "Maternal Grandfather", 1);
    Person *maternalGrandmother = createPerson(NULL, FEMALE, "Maternal Grandmother", 1);

    Relation *paternalMarriage = addRelation(paternalGrandfather, paternalGrandmother);
    Relation *maternalMarriage = addRelation(maternalGrandfather, maternalGrandmother);

    Person *father = addChild(paternalMarriage, MALE, "Father", 1);
    Person *fatherYoungerSister = addChild(paternalMarriage, FEMALE, "FatherYoungerSister", 1);
    Person *motherOlderBrother = addChild(maternalMarriage, MALE, "MotherOlderBrother", 1);
    Person *motherOlderSister = addChild(maternalMarriage, FEMALE, "MotherOlderSister", 1);
    Person *fatherYoungerBrother = addChild(paternalMarriage, MALE, "FatherYoungerBrother", 1);
    Person *mother = addChild(maternalMarriage, FEMALE, "Mother", 1);

    Person *fatherYoungerSisterHusband = createPerson(NULL, MALE, "FatherYoungerSisterHusband", 1);
    Person *motherOlderBrotherWife = createPerson(NULL, FEMALE, "MotherOlderBrotherWife", 1);
    Person *motherOlderSisterHusband = createPerson(NULL, MALE, "MotherOlderSisterHusband", 1);
    Person *fatherYoungerBrotherWife = createPerson(NULL, FEMALE, "FatherYoungerBrotherWife", 1);

    Relation *parentsMarriage = addRelation(father, mother);
    Relation *fatherYoungerSisterMarriage = addRelation(fatherYoungerSisterHusband, fatherYoungerSister);
    Relation *motherOlderBrotherMarriage = addRelation(motherOlderBrotherWife, motherOlderBrother);
    Relation *motherOlderSisterMarriage = addRelation(motherOlderSisterHusband, motherOlderSister);
    Relation *fatherYoungerBrotherMarriage = addRelation(fatherYoungerBrotherWife, fatherYoungerBrother);

    Person *child1 = addChild(parentsMarriage, MALE, "Child1", 1);
    Person *child2 = addChild(parentsMarriage, FEMALE, "Child2", 1);
    Person *child3 = addChild(parentsMarriage, MALE, "Child3", 1);
    Person *child4 = addChild(parentsMarriage, FEMALE, "Child4", 1);

    Person *cousin1 = addChild(fatherYoungerSisterMarriage, MALE, "Cousin1", 1);
    Person *cousin2 = addChild(fatherYoungerSisterMarriage, FEMALE, "Cousin2", 1);
    Person *cousin3 = addChild(fatherYoungerBrotherMarriage, MALE, "Cousin3", 1);
    Person *cousin4 = addChild(fatherYoungerBrotherMarriage, FEMALE, "Cousin4", 1);

    Person *cousin5 = addChild(motherOlderBrotherMarriage, MALE, "Cousin5", 1);
    Person *cousin6 = addChild(motherOlderBrotherMarriage, FEMALE, "Cousin6", 1);
    Person *cousin7 = addChild(motherOlderSisterMarriage, MALE, "Cousin7", 1);
    Person *cousin8 = addChild(motherOlderSisterMarriage, FEMALE, "Cousin8", 1);

    printf("**Predefined Pedigree Loaded**\n");
}

void startMenu()
{
    printf("Welcome to the Pedigree Program\n");
    int choice, personID;
    do{
        printf("\n\n****Menu*****\n");
        printf("Enter your choice \n");
        printf("1. Use Predefined Pedigree\n");
        printf("2. Add Person to Parents\n");
        printf("3. Display Person\n");
        printf("4. Display Children\n");
        printf("5. Display Cousins\n");
        printf("6. Display All Persons\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            usePredefinedPedigree();
            break;
        case 2:
            readPersonAndParents();
            break;
        case 3:
            printf("Enter the id of the person to display\n");
            scanf("%d", &personID);
            displayPerson(findPersonById(personID));
            break;
        case 4:
            printf("Enter the id of the person to display\n");
            scanf("%d", &personID);
            displayChildren(findPersonById(personID));
            break;
        case 5:
            printf("Enter the id of the person to display\n");
            scanf("%d", &personID);
            displayCousins(findPersonById(personID));
            break;
        case 6:
            displayPersonList();
            break;
        case 7:
            printf("Exiting\n");
            break;  
        default:
            printf("Invalid choice\n");
            break;
        }
    }while (choice != 7);    
}