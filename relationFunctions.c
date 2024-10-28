Relation *createRelation(Person *male, Person *female)
{
    Relation *newRelation = (Relation *)malloc(sizeof(Relation));
    newRelation->male = male;
    newRelation->female = female;
    return newRelation;
}

void addRelation(Person *male, Person *female)
{
    Relation *newRelation = createRelation(male, female);

    if (male->firstRelation != NULL)
    {
        Relation *currentRelationMale = male->firstRelation;
        while (currentRelationMale->maleNextRelation)
            currentRelationMale = currentRelationMale->maleNextRelation;
        currentRelationMale->maleNextRelation = newRelation;
    }
    else
        male->firstRelation = newRelation;

    if (female->firstRelation != NULL)
    {
        Relation *currentRelationFemale = female->firstRelation;
        while (currentRelationFemale->femaleNextRelation)
            currentRelationFemale = currentRelationFemale->femaleNextRelation;
        currentRelationFemale->femaleNextRelation = newRelation;
    }
    else
        female->firstRelation = newRelation;
}