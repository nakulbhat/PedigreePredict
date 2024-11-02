
//personFunctions.c
int generateID();
personListNode **getPersonListHead();
Person* findPersonById(int id);
void addPersonToList(Person *person);
Person *createPerson(Relation *relOfOrg, gender gender, char name[], bool bypassCharacteristicReading);
Person *addChild(Relation *relOfOrg, gender gen, char name[], bool bypassCharacteristicReading);

//relationFunctions.c
Relation *createRelation(Person*male, Person*female);
Relation *addRelation(Person *male, Person *female);
Relation* findRelationById(int fatherid, int motherid);
bool siblingExists(Person* person);
bool isSibling(Person *person1, Person *person2);
bool isChild(Person *parent, Person *child);
bool isCousin(Person *person1, Person *person2);
bool isPartner(Person *person1, Person *person2);
int getRelationType(Person *person1, Person *person2);

//inputFunctions.c
double *normaliseProbabilities(double *probabilities);
double *calculateCharacteristicProbabilities(double *a, double *b);
double *getProbabilities(Relation *relOfOrg, bool bypassCharacteristicReading);
void readPersonAndParents();

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