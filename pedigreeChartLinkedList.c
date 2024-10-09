
typedef enum gender {MALE, FEMALE} gender;

typedef struct Person
{
    gender gen;
    int id;
    struct Relation* relationOfOrigin;
    int characteristics[10];
    struct Person* prevSibling;
    struct Person* nextSibling;
    struct Relation* firstRelation;
}Person;

typedef struct Relation
{
    struct Person* person1;
    struct Person* person2;
    struct Person* firstChild;
    int characteristics[20];
    struct Relation* p1nextRelation;
    struct Relation* p2nextRelation;
};

