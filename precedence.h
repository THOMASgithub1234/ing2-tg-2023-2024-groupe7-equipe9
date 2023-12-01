//
// Created by arcis on 23/11/2023.
//

#ifndef ING2_TG_2023_2024_GROUPE7_EQUIPE9_PRECEDENCE_H
#define ING2_TG_2023_2024_GROUPE7_EQUIPE9_PRECEDENCE_H



#define TACHEMAX 36 // Nombre maximal de tâches

struct Task {
    int id;
    float duree;
    float debut;
};

float pert(int graph[TACHEMAX][TACHEMAX], struct Task tache[TACHEMAX], int num_tasks);
int mainPrecedence;
#endif

