#include "../include/structs.h"
#include "../include/personFunctions.h"
#include "../include/relationFunctions.h"
#include "../include/inputFunctions.h"
#include "../include/displayFunctions.h"
#include "../include/menu.h"



double *normaliseProbabilities(double *probabilitiesArray)
{
    double total = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        total += probabilitiesArray[i];
    }
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        probabilitiesArray[i] /= total;
    }
    return probabilitiesArray;
}

double *calculateCharacteristicProbabilities(double *parent1, double *parent2)
{
    double *probabilities = (double *)malloc(sizeof(double) * ARRAY_SIZE);
    probabilities[0] = ((parent1[0] * (4 * parent2[0] + 2 * parent2[1]) + parent1[1] * (2 * parent2[0] + 2 * parent2[1])) / 4);
    probabilities[1] = ((parent1[0] * (2 * parent2[1] + 4 * parent2[2]) + parent1[1] * (2 * (parent2[0] + parent2[1] + parent2[2])) + parent1[2] * (4 * parent2[0] + 2 * parent2[1])) / 4);
    probabilities[2] = ((parent1[1] * (parent2[1] + 2 * parent2[2]) + parent1[2] * (2 * parent2[1] + 4 * parent2[2])) / 4);

    return probabilities;
}

double *getProbabilities(Relation *relOfOrg, bool bypassCharacteristicReading)
{
    int choice = 0;
    if (bypassCharacteristicReading == 0)
    {
        printf("Do you want to enter characteristics of the person?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);
    }
    if (choice == 1)
    {
        double *probabilities = (double *)malloc(sizeof(double) * ARRAY_SIZE);
        printf("Enter probabilities of the person having the following characteristics\n");
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            printf("Enter probability of characteristic %d\n", i + 1);
            scanf("%lf", &probabilities[i]);
        }
        return normaliseProbabilities(probabilities);
    }
    else if (relOfOrg == NULL)
    {
        double *probabilities = (double *)malloc(sizeof(double) * ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            probabilities[i] = 0.333;
        }
        return normaliseProbabilities(probabilities);
    }
    else
    {
        return normaliseProbabilities(calculateCharacteristicProbabilities(relOfOrg->male->characteristics, relOfOrg->female->characteristics));
    }
}

void readPersonAndParents()
{
    int mode;
    printf("Enter mode\n");
    printf("1. Read from one-line\n");
    printf("2. Read from user input\n");
    scanf("%d", &mode);
    char name[MAX_NAME_LENGTH];
    int gen, fatherID, motherID;
    if (mode == 1)
    {
        printf("Enter Details of Patient in one-line. Use tab to separate entries.");
        printf("\nName\tisMale\tFatherID\tMotherID\n");
        scanf("%s\t%d\t%d\t%d", name, &gen, &fatherID, &motherID);
    }
    else if (mode == 2)
    {
        printf("Enter name of the person\n");
        scanf("%s", name);
        printf("Choose gender\n");
        printf("1. Male\n");
        printf("2. Female\n");
        scanf("%d", &gen);
        printf("Enter ID of father\n");
        scanf("%d", &fatherID);
        printf("Enter ID of mother\n");
        scanf("%d", &motherID);
    }
    Person *father = findPersonById(fatherID);
    Person *mother = findPersonById(motherID);
    Relation *marriage = findRelationById(fatherID, motherID);
    if (marriage == NULL)
    {
        marriage = addRelation(father, mother);
    }
    addChild(marriage, gen == 1 ? MALE : FEMALE, name, 0);
}

