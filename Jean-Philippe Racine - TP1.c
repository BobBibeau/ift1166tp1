#include <stdio.h>
#define EMPLOYES "employes.txt"
#define ERREUR_FICHIER 0


typedef struct {
    char nom[26];
    char poste;
    float heures;
    float taux;
} employe;

employe getEmploye(char *nom, char poste, float heures, float taux) {
    employe x;
    x.nom = nom;
    x.poste = poste;
    x.heures = heures;
    x.taux = taux;
    return x
}
    
void collecterDonnees(char *nom, char poste, float heures, float taux) {

    


int lireFichier() {
    FILE *F;
    int i;
    int j;
    employe dossierEmploye[30];
    if (fopen(EMPLOYES, "r") == NULL) {
        return ERREUR_FICHIER;
    }
    else {
        F = fopen(EMPLOYES, "r");
        while((i != EOF) && (i != '\n')) {
            
        }
    }
}
int main() {
    printf("test\n");
    return 0;
}
    