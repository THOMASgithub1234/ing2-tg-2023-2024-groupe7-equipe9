//
// Created by enfants on 23/11/2023.
//

#ifndef ING2_TG_2023_2024_GROUPE7_EQUIPE9_EXCLUSIONS_H
#define ING2_TG_2023_2024_GROUPE7_EQUIPE9_EXCLUSIONS_H
typedef struct {
    int op1;
    int op2;
} Exclusion;

// Structure pour représenter une station
typedef struct {
    int *operations;
    int nbOperations;
} Station;

void lireContraintes(char *nomFichier, Exclusion **contraintes, int *nbContraintes);

void obtenirStations(Exclusion *contraintes, int nbContraintes, Station **stations, int *nbStations);

void afficherStations(Station *stations, int nbStations);

#endif //ING2_TG_2023_2024_GROUPE7_EQUIPE9_EXCLUSIONS_H
