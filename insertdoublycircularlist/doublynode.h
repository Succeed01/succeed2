#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H


typedef struct cellule {
    int val;
    struct cellule* suiv;
    struct cellule* prec;
} liste; 
typedef liste* list;

list createnode(int n);
list inserthead ( list l, int info);
list insertend ( list l, int info);
void display (list l);

#endif