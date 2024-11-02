#ifndef INPUT_FUNCTIONS
#define INPUT_FUNCTIONS

#include "structs.h"

double *normaliseProbabilities(double *probabilities);
double *calculateCharacteristicProbabilities(double *a, double *b);
double *getProbabilities(Relation *relOfOrg, bool bypassCharacteristicReading);
void readPersonAndParents();

#endif