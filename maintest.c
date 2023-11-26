#include "exclusionstest.h"
/*
int main() {
    // Déclaration et initialisation des variables
    Exclusion *contraintes;
  
    int nbContraintes;

    // Lecture des contraintes à partir du fichier
    lireContraintes("exclusions.txt", &contraintes, &nbContraintes);

    // Obtention du nombre de stations nécessaires et des opérations par station
    Station *stations = NULL;
    int nbStations;
    obtenirStations(contraintes, nbContraintes, &stations, &nbStations);

    // Affichage du résultat
    printf("Nombre de stations necessaires : %d\n", nbStations);
    afficherStations(stations, nbStations);

    // Libération de la mémoire allouée
    free(contraintes);
    for (int i = 0; i < nbStations; i++) {
        free(stations[i].operations);
    }
    free(stations);

    return 0;
}
*/