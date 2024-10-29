
#define STRUCTS_INCLUDED 1
#define MAX_NAME_LENGTH 25

typedef enum gender
{
    MALE,
    FEMALE
} gender;

typedef struct Person
{
    gender gender;
    char name[MAX_NAME_LENGTH];
    int id;
    struct Relation *relationOfOrigin;
    int characteristics[10];
    struct Person *prevSibling;
    struct Person *nextSibling;
    struct Relation *firstRelation;
} Person;

typedef struct Relation
{
    struct Person *male;
    struct Person *female;
    struct Person *firstChild;
    int characteristics[20];
    struct Relation *maleNextRelation;
    struct Relation *femaleNextRelation;
} Relation;
