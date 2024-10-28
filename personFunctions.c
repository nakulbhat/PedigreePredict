
int generateID()
{
    static int count = 0;
    count++;
    return count;
}

Person *createPerson(Relation *relOfOrg, gender gender, char name[], int characteristics[])
{
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->relationOfOrigin = relOfOrg;
    newPerson->id = generateID();
    strcpy(newPerson->name, name);
    newPerson->gender = gender;
    memcpy(newPerson->characteristics, characteristics, sizeof(newPerson->characteristics));
    return newPerson;
}

void addSibling(Relation *relOfOrg, gender gen, char name[], int characteristics[])
{
    Person *newPerson = createPerson(relOfOrg, gen, name, characteristics);

    Person *kid = relOfOrg->firstChild;

    if (kid == NULL)
        relOfOrg->firstChild = newPerson; // if no kids yet, then add as first kid
    // iterate until a kid has no nextSibling
    else
    {
        while (kid->nextSibling)
            kid = kid->nextSibling;
        newPerson->prevSibling = kid;
        kid->nextSibling = newPerson;
    }
}

void displayPerson(Person *person)
{
    if (person == NULL)
    {
        printf("Person is NULL\n");
        return;
    }

    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Gender: %s\n", person->gender == MALE ? "Male" : "Female");
    printf("Characteristics: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", person->characteristics[i]);
    }
    printf("\n");

    if (person->relationOfOrigin != NULL)
    {
        char* father = person->relationOfOrigin->male->name;
        char* mother = person->relationOfOrigin->female->name;
        printf("Relation of Origin: Exists; Father: %s    Mother: %s\n", father, mother);
    }
    else
    {
        printf("Relation of Origin: NULL\n");
    }

    if (person->prevSibling != NULL)
    {
        printf("Previous Sibling: %s\n", person->prevSibling->name);
    }
    else
    {
        printf("Previous Sibling: NULL\n");
    }

    if (person->nextSibling != NULL)
    {
        printf("Next Sibling: %s\n", person->nextSibling->name);
    }
    else
    {
        printf("Next Sibling: NULL\n");
    }

    if (person->firstRelation != NULL)
    {
        char *spouse;
        if (person->gender == MALE)
            spouse = person->firstRelation->female->name;
        else
            spouse = person->firstRelation->male->name;
        printf("First Relation: Exists, Spouse: %s\n", spouse);
    }
    else
    {
        printf("First Relation: NULL\n");
    }
}