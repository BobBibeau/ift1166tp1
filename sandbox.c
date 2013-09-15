#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EMP "employes.txt"
#define NEXT_ITEM strtok(NULL, " ")
#define MAX_LONG_NOM 25
#define MAX_LONG_POSTE 14
#define MAX_NB_EMP 30


typedef struct {
    char nom[MAX_LONG_NOM + 1];
    char poste;
    float heures;
    float taux;
} employe;

void formaterEmp(char *str, employe *ptr) {
    char tempNom[100];
    strtok(str, " ");
    strcpy(tempNom, str);
    str = NEXT_ITEM;
    sprintf(ptr->nom, "%s %s", tempNom, str);
    str = NEXT_ITEM;
    ptr->poste = str[0];
    str = NEXT_ITEM;
    ptr->heures = atof(str);
    str = NEXT_ITEM;
    ptr->taux = atof(str);
}

void getPoste(char c, char *str) {
    switch(toupper(c)) {
        case 'A' :
            strcpy(str, "Analyste");
            break;
        case 'O' :
            sprintf(str, "Operateur");
            break;
        case 'P' :
            sprintf(str, "Programmeur");
            break;
        case 'S' :
            sprintf(str, "Secretaire");
            break;
        default :
            sprintf(str, "Poste invalide");
            break;
    }
}

int nbProgCond() {

}

int nbOpCond() {

}

int nbSecCond() {

}

void afficherOp() {

}

void afficherProg() {

}


void lireFichier(char *fichier, employe empLire[], int *nb) {
    char getLine[100];
    int i = 0;
    FILE * aLire = fopen(fichier, "r");
    while (!feof(aLire)) {
        fgets(getLine, 100, aLire);
        formaterEmp(getLine, &empLire[i]);
        i++;
    }
    *nb = i;
    fclose(aLire);
}
int main() {
    char str[MAX_LONG_NOM + 1];
    char p[MAX_LONG_POSTE + 1];
    int i = 0;
    employe y[30];
    lireFichier(EMP, y, &i);
    for ( ; i>0; i--) {
        getPoste(y[i-1].poste, p);
        printf("\nEmploye #%d - Nom:     %s", i, y[i-1].nom);
        printf("\nEmploye #%d - Poste:   %s", i, p);
        printf("\nEmploye #%d - Heures:  %4.1fh par semaine", i, y[i-1].heures);
        printf("\nEmploye #%d - Taux:    %5.2f$ de l'heure", i, y[i-1].taux);
        printf("\n");
    }
    return 0;
}
