#include "precedence.h"
#include <stdio.h>
#include <stdlib.h>

float pert(int graph[TACHEMAX][TACHEMAX], struct Task tache[TACHEMAX], int num_tasks) {
    // Calcul des dates au plus tôt pour chaque tâche
    for (int i = 0; i < num_tasks; ++i) {
        float maxEarlyStart = 0;
        for (int j = 0; j < num_tasks; ++j) {
            if (graph[j][i] == 1) {
                if (tache[j].debut + tache[j].duree > maxEarlyStart) {
                    maxEarlyStart = tache[j].debut + tache[j].duree;
                }
            }
        }
        tache[i].debut = maxEarlyStart;
    }

    // Recherche de la tâche finale pour obtenir la durée minimale du projet
    float dureeminimal = 0;
    for (int i = 0; i < num_tasks; ++i) {
        if (tache[i].debut + tache[i].duree > dureeminimal) {
            dureeminimal = tache[i].debut + tache[i].duree;
        }
    }

    return dureeminimal;
}

int mainPrecedence() {
    FILE *file = fopen("precedences.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    int graphe[TACHEMAX][TACHEMAX] = {0}; // Matrice d'adjacence pour représenter le graphe
    struct Task tasks[TACHEMAX];

    int a, b;
    float Duree;
    int num_tasks = 0;

    while (fscanf(file, "%d %d %f", &a, &b, &Duree) == 3) {
        graphe[a - 1][b - 1] = 1;
        tasks[num_tasks].id = b;
        tasks[num_tasks].duree = Duree;
        tasks[num_tasks].debut = 0;
        num_tasks++;
    }

    fclose(file);

    float Dureemin = pert(graphe, tasks, num_tasks);
    printf("Durée minimale du projet : %.2f seconde.\n", Dureemin);


}
