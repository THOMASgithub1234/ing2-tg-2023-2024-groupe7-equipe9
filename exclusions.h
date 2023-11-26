//
// Created by enfants on 23/11/2023.
//

#ifndef ING2_TG_2023_2024_GROUPE7_EQUIPE9_EXCLUSIONS_H
#define ING2_TG_2023_2024_GROUPE7_EQUIPE9_EXCLUSIONS_H
// Structure pour représenter une paire d'opérations
struct ExclusionPair {
    int operation1;
    int operation2;
};

// Structure pour représenter une opération avec son nombre de paires associées
struct Operation {
    int operation;
    int numPairs;
};
int compareOperations(const void *a, const void *b);
void lirecontrainte(struct ExclusionPair *exclusions, int *numExclusions);
int calculateMinStations(struct ExclusionPair *exclusions, int numExclusions, int *stations, int *numOperationsInStation);
void printOperationsInStations(int *stations, int numStations, int *numOperationsInStation);

#endif //ING2_TG_2023_2024_GROUPE7_EQUIPE9_EXCLUSIONS_H
