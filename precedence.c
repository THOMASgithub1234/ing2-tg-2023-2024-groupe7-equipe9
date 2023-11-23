//
// Created by arcis on 23/11/2023.
//

#include "precedence.h"
#include <stdlib.h>

#include <stdio.h>
#define MAX_NODES 100 // Nombre maximal de nœuds dans le graphe

void lireContraintes(char *nomFichier, int graphe[MAX_NODES][MAX_NODES]) {
    FILE *file = fopen("precedences.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }


