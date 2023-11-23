//
// Created by arcis on 23/11/2023.
//

#include "precedence.h"
#include <stdlib.h>

#include <stdio.h>
#define MAX_NODES 100 // Nombre maximal de nœuds dans le graphe

void lireContrainte(char *precedence, int graphe[MAX_NODES][MAX_NODES]) {
    FILE *file = fopen("precedences.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    int a, b;
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = 0; j < MAX_NODES; ++j) {
            graphe[i][j] = 0;
        }
    }

    while (fscanf(file, "%d %d", &a, &b) == 2) {
        graphe[a - 1][b - 1] = 1;
    }

    fclose(file);
}

void afficherGraphe(int graphe[MAX_NODES][MAX_NODES]) {
    printf("Graphe de precedance :\n");
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = 0; j < MAX_NODES; ++j) {
            if (graphe[i][j] == 1) {
                printf("%d -> %d\n", i + 1, j + 1);
            }
        }
    }
}


int main() {
    int graphe[MAX_NODES][MAX_NODES]; // Matrice d'adjacence pour représenter le graphe

    lireContrainte("contraintes_precedence.txt", graphe);

    afficherGraphe(graphe);

    return 0;
}

