
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
    int id;
    displayPersonList();
    usePredefinedPedigree();
    displayPersonList();
    //displayPersonById(15);
    //readPersonAndParents();
    //displayPersonList();
    fflush(stdin);
    scanf("%d", &id);
    displayPersonById(id);
    fflush(stdin);
    scanf("%d", &id);
    displayPersonById(id);
    return 0;
}
