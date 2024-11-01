
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
    //startMenu();
    usePredefinedPedigree();
    displayPersonList();
    findPersonById(5);
    // displayPersonById(1);
    // printf("s");
    // printf("%d\n", getRelationType(findPersonById(5), findPersonById(2)));
    // printf("%d\n", getRelationType(findPersonById(5), findPersonById(10)));
    // printf("%d\n", getRelationType(findPersonById(5), findPersonById(10)));
    // printf("%d\n", getRelationType(findPersonById(5), findPersonById(10)));
    return 0;
}
