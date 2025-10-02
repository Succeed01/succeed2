#include<stdio.h>
#include<stdlib.h>

struct liste{
    int info;
    struct liste *next;
};
typedef struct liste *list;

list createlist(int n) {
    if (n <= 0) return NULL;
    
    list l = NULL, last = NULL;
    int i, v;
    
    for(i = 0; i < n; i++) {
        printf("Enter the value of the element %d: ", i+1);
        scanf("%d", &v);
        
        list p = (list)malloc(sizeof(struct liste));
        if(p == NULL) {
            printf("Erreur d'allocation");
            exit(1);
        }
        p->info = v;
        p->next = NULL;
        
        if(l == NULL) {
            l = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
    }
    return l;
}

list deleteElement(list l, int val) {
    if (l == NULL) {
        printf("The list is already empty\n");
        return NULL;
    }
    
    list cour = l, prev = NULL;
    
    // Case 1: Delete first element
    if (l->info == val) {
        list temp = l;
        l = l->next;
        free(temp);
        return l;
    }
    
    // Case 2: Delete element in middle or end
    prev = l;
    cour = l->next;
    
    while(cour != NULL) {
        if (cour->info == val) {
            prev->next = cour->next;
            free(cour);
            return l;
        }
        prev = cour;
        cour = cour->next;
    }
    
    printf("Value %d not found in the list\n", val);
    return l;
}

void display(list l) {
    if (l == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    list cour = l;
    printf("List elements: ");
    while(cour != NULL) {
        printf("%d", cour->info);
        if(cour->next != NULL) {
            printf(" -> ");
        }
        cour = cour->next;
    }
    printf("\n");
}

void freeList(list l) {
    list cour = l;
    while(cour != NULL) {
        list temp = cour;
        cour = cour->next;
        free(temp);
    }
}

int main() {
    list l = NULL;
    int choice, n, val;
    
    do {
        printf("**************************************************\n");
        printf("________________MENU______________\n");
        printf("**************************************************\n");
        printf("1. Create a list\n");
        printf("2. Delete one element in the list\n");
        printf("3. Display the list\n");
        printf("0. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            if(l != NULL) {
                freeList(l);
            }
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            l = createlist(n);
            break;
        case 2:
            if(l == NULL) {
                printf("Please create a list first!\n");
            } else {
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                l = deleteElement(l, val);
            }
            break;
        case 3:
            display(l);
            break;
        case 0:
            printf("Thank you for using the program\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    } while(choice != 0);
    
    // Free memory before exiting
    if(l != NULL) {
        freeList(l);
    }
    
    return 0;
}