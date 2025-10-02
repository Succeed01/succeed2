#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d’un nœud
struct Node {
    int data;
    struct Node* next;
};

// Fonction pour créer un nouveau nœud
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un élément dans une liste triée
struct Node* insertSorted(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    // Cas 1 : liste vide
    if (head == NULL) {
        return newNode;
    }

    // Cas 2 : insertion en tête
    if (data < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Cas 3 : insertion au milieu ou à la fin
    struct Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Fonction pour créer une liste triée à partir de valeurs saisies
struct Node* createSortedList() {
    struct Node* head = NULL;
    int n, data;
    
    printf("Entrez le nombre d'éléments de la liste : ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        scanf("%d", &data);
        head = insertSorted(head, data);
    }
    
    return head;
}

// Fonction pour afficher la liste
void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("La liste est vide\n");
        return;
    }
    
    printf("Liste triée : ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Fonction pour libérer la mémoire
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Programme principal avec menu interactif
int main() {
    struct Node* head = NULL;
    int choice, data;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Créer une nouvelle liste triée\n");
        printf("2. Insérer un élément dans la liste\n");
        printf("3. Afficher la liste\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (head != NULL) {
                    freeList(head);
                }
                head = createSortedList();
                printf("Liste créée avec succès\n");
                break;
                
            case 2:
                if (head == NULL) {
                    printf("Veuillez d'abord créer une liste (option 1)\n");
                } else {
                    printf("Entrez la valeur à insérer : ");
                    scanf("%d", &data);
                    head = insertSorted(head, data);
                    printf("%d inséré dans la liste triée\n", data);
                }
                break;
                
            case 3:
                printList(head);
                break;
                
            case 4:
                printf("Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide !\n");
                break;
        }
    } while (choice != 4);
    
    // Libération de la mémoire
    if (head != NULL) {
        freeList(head);
    }
    
    return 0;
}