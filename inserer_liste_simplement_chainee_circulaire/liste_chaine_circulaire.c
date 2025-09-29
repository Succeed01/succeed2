#include<stdio.h>
#include<stdlib.h>
#include"liste_chainee.h"

// Creation d'un noeud
list creernoeud(int n) {
    if (n <= 0 )
    return NULL;
    list  l = NULL, p = NULL, der = NULL;
    int i; 
    for (i = 0; i < n; i++ ){
        p = (list)malloc(sizeof(cellule));
        return l;
    }
    printf("entrer l'element\n");
    scanf("%d", &(p->val));
    if (l == NULL){
        p->suiv = p;
        l = p;
        der = p;  
    } else {
        p->suiv = l;
        der->suiv = p;
        der = p;
    }
}
return l;

// Insertion tete
liste inserertete(list l, int x){
    list m = (list)malloc(sizeof(celulule));
    if (m == NULL){
        printf("erreur :alloacation memoire");
        return l;
    }
    m->val = x;
    if (l == NULL){
        m->suiv = m;
        l = m;
        return m;
    } else{
        m->suiv = l;
        der-> = m;
        return m;
    }
}

// Insertion fin
liste insererfin(list l, int x){
    list m = (list)malloc(sizeof(cellule));
    if (m == NULL){
        printf("erreur :allocation memoire");
        return l;
    } else{
        m->suis = l;
        der->suiv = m;
        return l;
    }
}

// Affichage liste
void display(list l){
    if (l == NULL){
    printf("la liste est vide");
    return;
    }
    courant = l;
    printf("element de la liste");
    do{
        printf("%d", courant->val);
        if (courant->val != l){
            courant = courant->suiv;
        } 
    } while (courant != l);
    printf("\n");
    return 0;
}