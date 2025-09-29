#ifndef LISTE_TRIEE_H
#define LISTE_TRIEE_H

// Structure d'une cellule 
struct cellule{
    int val;
    struct cellule* suiv;
} liste;
typedef liste* list;

// Fonction
list creernoeud (int n);
list inserertete (list l, int x);
list insererfin (list l, int x);
void display (list l);

#endif