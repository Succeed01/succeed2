#include <stdio.h>
#include <stdlib.h>

// Structure d'une cellule 
struct cellule{
    int val;
    struct cellule* suiv;
};
typedef struct cellule liste;
typedef liste* list;

// Fonctions
list creernoeud(int n);
list inserertete(list l, int x);
list insererfin(list l, int x);
void display(list l);

// Creation d'un noeud
list creernoeud(int n) {
    if (n <= 0)
        return NULL;
    
    list l = NULL, p = NULL, der = NULL;
    int i;
    
    for (i = 0; i < n; i++) {
        p = (list)malloc(sizeof(liste));
        if (p == NULL) {
            printf("Erreur d'allocation mémoire");
            return l;
        }
        
        printf("Entrer l'element: ");
        scanf("%d", &(p->val));
        
        if (l == NULL) {
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
}

// Insertion tete
list inserertete(list l, int x) {
    list m = (list)malloc(sizeof(liste));
    if (m == NULL) {
        printf("Erreur : allocation memoire");
        return l;
    }
    m->val = x;
    
    if (l == NULL) {
        m->suiv = m;
        return m;
    } else {
        // Trouver le dernier élément
        list der = l;
        while (der->suiv != l) {
            der = der->suiv;
        }
        
        m->suiv = l;
        der->suiv = m;
        return m;
    }
}

// Insertion fin
list insererfin(list l, int x) {
    list m = (list)malloc(sizeof(liste));
    if (m == NULL) {
        printf("Erreur : allocation memoire");
        return l;
    }
    m->val = x;
    
    if (l == NULL) {
        m->suiv = m;
        return m;
    } else {
        // Trouver le dernier élément
        list der = l;
        while (der->suiv != l) {
            der = der->suiv;
        }
        
        m->suiv = l;
        der->suiv = m;
        return l;
    }
}

// Affichage liste
void display(list l) {
    if (l == NULL) {
        printf("La liste est vide\n");
        return;
    }
    
    list courant = l;
    printf("Elements de la liste: ");
    do {
        printf("%d", courant->val);
        courant = courant->suiv;
        if (courant != l) {
            printf(" -> ");
        }
    } while (courant != l);
    printf("\n");
}

// Programme principal
int main() {
    int z, y, n;
   
    // Creation de la liste
    list nod;
    printf("Entrer la taille de la liste: ");
    scanf("%d", &n);
    nod = creernoeud(n);

    // Insertion en tete 
    printf("Entrer la valeur a inserer en tete: ");
    scanf("%d", &z);
    nod = inserertete(nod, z);

    // Insertion en fin
    printf("Entrer la valeur a inserer a la fin: ");
    scanf("%d", &y);
    nod = insererfin(nod, y);

    // Affichage de la liste
    display(nod);
    
    return 0;
}