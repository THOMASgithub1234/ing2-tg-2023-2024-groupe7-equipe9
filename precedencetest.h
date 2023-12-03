//
// Created by Arcis/Gabriel on 03/12/2023.
//

#ifndef ING2_TG_2023_2024_GROUPE7_EQUIPE9_PRECEDENCETEST_H
#define ING2_TG_2023_2024_GROUPE7_EQUIPE9_PRECEDENCETEST_H

#define TACHEMAX 36 // Nombre maximal de tâches

struct Task {
    int id;
    float duree;
    float debut;
    int critical;
};

float pert(int graph[TACHEMAX][TACHEMAX], struct Task tache[TACHEMAX], int num_tasks, int criticalPath[TACHEMAX]);
int mainPrecedence();
void afficherCheminCritique(struct Task tache[TACHEMAX], int num_tasks, int criticalPath[TACHEMAX]);

#endif //ING2_TG_2023_2024_GROUPE7_EQUIPE9_PRECEDENCETEST_H
