#include <stdio.h>
#include <stdlib.h>

// doublynode.h
#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

typedef struct cellule {
    int val;
    struct cellule* suiv;
    struct cellule* prec;
} liste; 
typedef liste* list;

list createnode(int n);
list inserthead(list l, int info);
list insertend(list l, int info);
void display(list l);

#endif

// doublynode.c
list createnode(int n) {
    if (n <= 0) return NULL;
    
    list l = NULL, p = NULL, last = NULL;
    int i;
    
    for (i = 0; i < n; i++) {
        p = (list)malloc(sizeof(liste));
        if (p == NULL) {
            printf("Allocation error");
            return l;
        }
        
        printf("Enter the element: ");
        scanf("%d", &(p->val));
        
        if (l == NULL) {
            p->suiv = p;
            p->prec = p;
            l = p;
            last = p;
        } else {
            p->prec = last;
            p->suiv = l;
            last->suiv = p;
            l->prec = p;
            last = p;
        }
    }
    return l;
}

list inserthead(list l, int info) {
    list k = (list)malloc(sizeof(liste));
    if (k == NULL) {
        printf("Allocation error");
        return l;
    }
    
    k->val = info;
    
    if (l == NULL) {
        k->suiv = k;
        k->prec = k;
        return k;
    } else {
        k->suiv = l;
        k->prec = l->prec;
        l->prec->suiv = k;
        l->prec = k;
        return k;  
    }
}

list insertend(list l, int info) {
    list k = (list)malloc(sizeof(liste));
    if (k == NULL) {
        printf("Allocation error");
        return l;
    }
    
    k->val = info;
    
    if (l == NULL) {
        k->suiv = k;
        k->prec = k;
        return k;
    } else {
        list last = l->prec;
        
        k->suiv = l;
        k->prec = last;
        last->suiv = k;
        l->prec = k;
        
        return l; 
    }
}

void display(list l) {
    if (l == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    list current = l;
    printf("List elements: ");
    
    do {
        printf("%d", current->val);
        current = current->suiv;
        if (current != l) printf(" <-> ");
    } while (current != l);
    
    printf("\n");
}

// main.c
int main() {
    int n, a, b;
    list nod;
    
    printf("Enter the length of the Node: ");
    scanf("%d", &n);
    nod = createnode(n);

    printf("Enter the value that you want to add on the head: ");
    scanf("%d", &a);
    nod = inserthead(nod, a);
    display(nod);
    
    printf("Enter the value that you want to add at the end: ");
    scanf("%d", &b);
    nod = insertend(nod, b);
    display(nod);

    return 0;
}