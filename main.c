
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

Person *createPerson(Relation *relOfOrg, gender gender, char name[]);
Person* addChild(Relation *relOfOrg, gender gen, char name[]);
double *calculateProbabilities(double *a, double *b);

void displayPerson(Person *person);
void displaySiblings(Person *person);
void displayChildren(Person *person);
void displayCousins(Person *person);

Relation *addRelation(Person *male, Person *female);

int main(){
    usePredefinedPedigree();
    displayPersonList();
    return 0;
}
