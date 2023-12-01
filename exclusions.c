//
// Created by enfants on 23/11/2023.
//

#include "exclusions.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERATIONS 35

// Fonction de comparaison pour le tri décroissant des opérations en fonction du nombre de paires
int compareOperations(const void *a, const void *b) {
    return ((struct Operation *)b)->numPairs - ((struct Operation *)a)->numPairs;
}

// Fonction pour lire les contraintes d'exclusion à partir d'un fichier
void lirecontrainte(struct ExclusionPair *exclusions, int *numExclusions) {
    FILE *file = fopen("exclusions.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    *numExclusions = 0;

    while (fscanf(file, "%d %d", &exclusions[*numExclusions].operation1, &exclusions[*numExclusions].operation2) == 2) {
        (*numExclusions)++;
    }

    fclose(file);
}

// Fonction pour déterminer le nombre minimal de stations nécessaires
int calculateMinStations(struct ExclusionPair *exclusions, int numExclusions, int *stations, int *numOperationsInStation) {
    int numStations = 0;

    // Initialiser le tableau des stations
    for (int i = 0; i < MAX_OPERATIONS; ++i) {
        stations[i] = -1; // -1 signifie que l'opération n'est pas attribuée à une station
    }

    // Créer un tableau d'opérations avec le nombre de paires associées
    struct Operation operations[MAX_OPERATIONS];
    for (int i = 0; i < MAX_OPERATIONS; ++i) {
        operations[i].operation = i + 1;
        operations[i].numPairs = 0;
    }

    // Compter le nombre de paires associées à chaque opération
    for (int i = 0; i < numExclusions; ++i) {
        operations[exclusions[i].operation1 - 1].numPairs++;
        operations[exclusions[i].operation2 - 1].numPairs++;
    }

    // Trier les opérations en fonction du nombre de paires (ordre décroissant)
    qsort(operations, MAX_OPERATIONS, sizeof(struct Operation), compareOperations);

    // Parcourir les opérations triées
    for (int i = 0; i < MAX_OPERATIONS; ++i) {
        int currentOperation = operations[i].operation;

        // Trouver la première station disponible sans créer de paire
        for (int j = 1; j <= numStations; ++j) {
            int isPair = 0;

            // Vérifier si l'ajout de l'opération crée une paire
            for (int k = 0; k < numExclusions; ++k) {
                if ((stations[exclusions[k].operation1 - 1] == j && exclusions[k].operation2 == currentOperation) ||
                    (stations[exclusions[k].operation2 - 1] == j && exclusions[k].operation1 == currentOperation)) {
                    isPair = 1;
                    break;
                }
            }

            // Si l'opération n'est pas une paire, l'attribuer à la station
            if (!isPair) {
                stations[currentOperation - 1] = j;
                numOperationsInStation[j]++;
                break;
            }
        }

        // Si aucune station n'est disponible sans créer de paire, ajouter une nouvelle station
        if (stations[currentOperation - 1] == -1) {
            numStations++;
            stations[currentOperation - 1] = numStations;
            numOperationsInStation[numStations]++;
        }
    }

    return numStations;
}

// Fonction pour afficher les opérations réalisées par chaque station
void printOperationsInStations(int *stations, int numStations, int *numOperationsInStation) {
    printf("Repartition des operations par station :\n");

    for (int i = 0; i < numStations; ++i) {
        printf("Station %d : ", i + 1);

        for (int j = 0; j < MAX_OPERATIONS; ++j) {
            if (stations[j] == i + 1) {
                printf("op%d ", j + 1);
            }
        }

        printf("\n");
    }



}

int mainExclusion (){
    struct ExclusionPair exclusions[MAX_OPERATIONS * (MAX_OPERATIONS - 1) / 2];
    int numExclusions;

    // Lecture des contraintes d'exclusion à partir du fichier
    lirecontrainte(exclusions, &numExclusions);

    int stations[MAX_OPERATIONS];
    int numOperationsInStation[MAX_OPERATIONS] = {0};

    // Calculer le nombre minimal de stations nécessaires et les opérations réalisées par chaque station
    int numStations = calculateMinStations(exclusions, numExclusions, stations, numOperationsInStation);

    // Afficher le résultat
    printf("Nombre minimal de stations necessaires : %d\n", numStations);
    printOperationsInStations(stations, numStations, numOperationsInStation);


}
