
//personFunctions.c
int generateID();
Person* findPersonById(int id);
void addPersonToList(Person *person);
double *normaliseProbabilities(double *probabilities);
double *calculateProbabilities(double *a, double *b);
double *getProbabilities(Relation *relOfOrg, int mode);
Person *createPerson(Relation *relOfOrg, gender gender, char name[], int characteristicsMode);
Person *addChild(Relation *relOfOrg, gender gen, char name[], int bypassCharacReading);
void readPersonAndParents();

//relationFunctions.c
Relation *createRelation(Person*male, Person*female);
Relation *addRelation(Person *male, Person *female);
Relation* findRelationById(int fatherid, int motherid);

//displayFunctions.c
void displayPerson(Person *person);
void displaySiblings(Person *person);
void displayChildren(Person *person);
void displayCousins(Person *person);
void displayPersonBrief(Person *person);
void displayPersonList();
void displayPersonById(int id);

//menu.c
void usePredefinedPedigree();
void startMenu();