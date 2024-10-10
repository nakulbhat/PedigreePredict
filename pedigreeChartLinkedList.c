
typedef enum gender {MALE, FEMALE} gender;

typedef struct Person
{
    gender gender;
    char name[25];
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
}Relation;

int generateID(){
    static int count = 0;
    count++;
    return count;
}

Person* createPerson(Relation* relOfOrg, gender gender, char name[] ,int characteristics[]){
    Person* newPerson = (Person*) malloc(sizeof(Person));
    newPerson->id = generateID();
}

void addSibling(Relation* relOfOrg, gender gender, char name[] ,int characteristics[]){

}

int main(){
    return 0;
}
