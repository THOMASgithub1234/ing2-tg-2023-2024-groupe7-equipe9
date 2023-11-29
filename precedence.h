//
// Created by arcis on 23/11/2023.
//

#ifndef ING2_TG_2023_2024_GROUPE7_EQUIPE9_PRECEDENCE_H
#define ING2_TG_2023_2024_GROUPE7_EQUIPE9_PRECEDENCE_H



#define MAX_TASKS 36 // Nombre maximal de tâches

struct Task {
    int id;
    float duration;
    float earlyStart;
};

float pert(int graph[MAX_TASKS][MAX_TASKS], struct Task tasks[MAX_TASKS], int num_tasks);
#endif

