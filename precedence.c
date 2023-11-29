#include "precedence.h"
#include <stdio.h>
#include <stdlib.h>

float pert(int graph[MAX_TASKS][MAX_TASKS], struct Task tasks[MAX_TASKS], int num_tasks) {
    // Calcul des dates au plus tôt (ES) pour chaque tâche
    for (int i = 0; i < num_tasks; ++i) {
        float maxEarlyStart = 0;
        for (int j = 0; j < num_tasks; ++j) {
            if (graph[j][i] == 1) {
                if (tasks[j].earlyStart + tasks[j].duration > maxEarlyStart) {
                    maxEarlyStart = tasks[j].earlyStart + tasks[j].duration;
                }
            }
        }
        tasks[i].earlyStart = maxEarlyStart;
    }

    // Recherche de la tâche finale pour obtenir la durée minimale du projet
    float minDuration = 0;
    for (int i = 0; i < num_tasks; ++i) {
        if (tasks[i].earlyStart + tasks[i].duration > minDuration) {
            minDuration = tasks[i].earlyStart + tasks[i].duration;
        }
    }

    return minDuration;
}

int main() {
    FILE *file = fopen("precedences.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    int graph[MAX_TASKS][MAX_TASKS] = {0}; // Matrice d'adjacence pour représenter le graphe
    struct Task tasks[MAX_TASKS];

    int a, b;
    float duration;
    int num_tasks = 0;

    while (fscanf(file, "%d %d %f", &a, &b, &duration) == 3) {
        graph[a - 1][b - 1] = 1;
        tasks[num_tasks].id = b;
        tasks[num_tasks].duration = duration;
        tasks[num_tasks].earlyStart = 0;
        num_tasks++;
    }

    fclose(file);

    float minDuration = pert(graph, tasks, num_tasks);
    printf("Durée minimale du projet : %.2f seconde.\n", minDuration);

    return 0;
}