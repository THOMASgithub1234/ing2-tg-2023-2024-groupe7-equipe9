#include <stdio.h>
#include <stdlib.h>
#include <precedence.h>

// Il faut qu'on déclare nos structures ici, celle-ci sont des exemples par rapport à ce que l'on va faire

// Fonctions pour gérer les différentes fonctionnalités
void lireContraintes();
void repartirOperations();
void afficherResultat();
void quitterProgramme();

/*int main() {
    int choix;

    do {
        // Affichage du menu
        printf("\nMenu :\n");
        printf("1. Lire les contraintes depuis le fichier\n");
        printf("2. Répartir les opérations par station\n");
        printf("3. Afficher le résultat\n");
        printf("4. Quitter le programme\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        // Switch case pour le choix des menu qui renvoie par la suite à un sous programme
        switch (choix) {
            case 1:
                lireContraintes();
                break;
            case 2:
                repartirOperations();
                break;
            case 3:
                afficherResultat();
                break;
            case 4:
                quitterProgramme();
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
        }

    } while (choix != 4);

    return 0;
}

void lireContraintes() {
    printf("Fonction non implémentée.\n");
}

void repartirOperations() {
    printf("Fonction non implémentée.\n");
}

void afficherResultat() {
    printf("Fonction non implémentée.\n");
}

void quitterProgramme() {
    printf("Merci d'avoir utilisé le programme. Au revoir!\n");
    exit(0);
}

*/