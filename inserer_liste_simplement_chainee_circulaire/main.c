#include<stdio.h>
#include<stdlib.h>
#include"liste_triee.h"

int main(){
  int z, y, n;
   
  //Creation de la liste
  list nod;
    printf("entrer la taille de la liste");
    scanf("%d", &n);
    nod = creernoeud(n);

    // Insertion en tete 
    printf("entrer la valeur a inserer en tete");
    scanf("%d", &z);
    nod = inserertete(nod, z);

    // Insertion en fin
    printf("entrer la valeur a inserer a la fin");
    scanf("%d", &y);
    nod = insererfin(nod, y);

    // Affichage le la liste
    display (nod, z);
    display (nod, y);
    return 0;
}