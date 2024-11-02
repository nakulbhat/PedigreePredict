
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

#include "functionList.h"

int main(){
    usePredefinedPedigree();
    Person *p1 =findPersonById(1);
    Person*p2 = findPersonById(4);
    displayPerson(p1);
    displayPerson(p2);
    printf("pass\n");
    isChild(p1,p2);
    printf("pass\n");
    isChild(p2,p1);
    printf("pass ischild\n");
    isChild(p1, p2) || isChild(p2, p1);
    printf("pass ischild bool\n");
    isSibling(p1,p2);
    printf("pass issibling\n");
    isPartner(p1,p2);

    // getRelationType(findPersonById(1), findPersonById(4)); // error is here
    // printf("pass\n");
    // printf("pass\n");
    // getRelationType(findPersonById(1), findPersonById(4)); // error is here
    // printf("pass\n");
    printf("%d", getRelationType(findPersonById(1), findPersonById(4)));
    return 0;
}
