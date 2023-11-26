///Sachant que le fichier était de base main.c et exclusion.h , il faut changer les if et tout car ici en blablatest
/*
#ifndef EXCLUSIONS_H
#define EXCLUSIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int op1;
    int op2;
} Exclusion;

typedef struct {
    int *operations;
    int nbOperations;
} Station;

void lireContraintes(char *exclusions, Exclusion **contraintes, int *nbContraintes) {
    FILE *fichier = fopen(exclusions, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Comptage du nombre de contraintes dans le fichier
    int nbLignes = 0;
    while (fscanf(fichier, "%*d %*d") == 2) {
        nbLignes++;
    }
    rewind(fichier);

    // Allocation de mémoire pour stocker les contraintes
    *contraintes = malloc(nbLignes * sizeof(Exclusion));
    if (*contraintes == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    // Lecture des contraintes à partir du fichier
    for (int i = 0; i < nbLignes; i++) {
        fscanf(fichier, "%d %d", &((*contraintes)[i].op1), &((*contraintes)[i].op2));
    }

    *nbContraintes = nbLignes;
    fclose(fichier);
}

void obtenirStations(Exclusion *contraintes, int nbContraintes, Station **stations, int *nbStations) {
    *nbStations = 0;

    for (int i = 0; i < nbContraintes; i++) {
        int station1 = -1;
        int station2 = -1;

        for (int j = 0; j < *nbStations; j++) {
            for (int k = 0; k < (*stations)[j].nbOperations; k++) {
                if ((*stations)[j].operations[k] == contraintes[i].op1) {
                    station1 = j;
                    break;
                }
            }
            if (station1 != -1) {
                break;
            }
        }

        for (int j = 0; j < *nbStations; j++) {
            for (int k = 0; k < (*stations)[j].nbOperations; k++) {
                if ((*stations)[j].operations[k] == contraintes[i].op2) {
                    station2 = j;
                    break;
                }
            }
            if (station2 != -1) {
                break;
            }
        }

        if (station1 == -1 && station2 == -1) {
            // Nouvelle station
            *stations = realloc(*stations, (*nbStations + 1) * sizeof(Station));
            (*stations)[*nbStations].operations = malloc(2 * sizeof(int));
            (*stations)[*nbStations].operations[0] = contraintes[i].op1;
            (*stations)[*nbStations].operations[1] = contraintes[i].op2;
            (*stations)[*nbStations].nbOperations = 2;
            (*nbStations)++;
        } else if (station1 != -1 && station2 == -1) {
            // Ajout de l'opération 2 à la station existante contenant l'opération 1
            (*stations)[station1].operations = realloc((*stations)[station1].operations,
                                                       ((*stations)[station1].nbOperations + 1) * sizeof(int));
            (*stations)[station1].operations[(*stations)[station1].nbOperations] = contraintes[i].op2;
            (*stations)[station1].nbOperations++;
        } else if (station1 == -1 && station2 != -1) {
            // Ajout de l'opération 1 à la station existante contenant l'opération 2
            (*stations)[station2].operations = realloc((*stations)[station2].operations,
                                                       ((*stations)[station2].nbOperations + 1) * sizeof(int));
            (*stations)[station2].operations[(*stations)[station2].nbOperations] = contraintes[i].op1;
            (*stations)[station2].nbOperations++;
        } else {
            // Les deux opérations existent déjà dans des stations distinctes, fusionner les stations
            if (station1 != station2) {
                int nouvelleTaille = (*stations)[station1].nbOperations + (*stations)[station2].nbOperations;
                (*stations)[station1].operations =
                        realloc((*stations)[station1].operations, nouvelleTaille * sizeof(int));
                for (int j = 0; j < (*stations)[station2].nbOperations; j++) {
                    (*stations)[station1].operations[(*stations)[station1].nbOperations + j] =
                            (*stations)[station2].operations[j];
                }
                (*stations)[station1].nbOperations = nouvelleTaille;

                // Supprimer la station 2
                for (int j = station2; j < *nbStations - 1; j++) {
                    (*stations)[j] = (*stations)[j + 1];
                }
                (*nbStations)--;
            }
        }
    }
}

void afficherStations(Station *stations, int nbStations) {
    for (int i = 0; i < nbStations; i++) {
        printf("Station %d : ", i + 1);
        for (int j = 0; j < stations[i].nbOperations; j++) {
            printf("op%d ", stations[i].operations[j] + 1); // Ajouter +1 ici pour afficher les indices corrects
        }
        printf("\n");
    }
}

#endif // EXCLUSIONS_H
*/