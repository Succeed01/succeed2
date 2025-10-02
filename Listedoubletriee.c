

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int val;
    struct DNode *prev;
    struct DNode *next;
} DNode;

static DNode *create_node(int val) {
    DNode *n = malloc(sizeof(DNode));
    if (n == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->val = val;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

DNode *insert_sorted(DNode *head, int val) {
    DNode *newn = create_node(val);

    
    if (head == NULL) {
        return newn;
    }

    if (val < head->val) {
        newn->next = head;
        head->prev = newn;
        return newn;
    }

    DNode *p = head;
    while (p->next != NULL && p->next->val <= val) {
        p = p->next;
    }

    /* Insérer newn après p */
    newn->next = p->next;
    newn->prev = p;
    p->next = newn;
    if (newn->next != NULL) {
        newn->next->prev = newn;
    }

    return head;
}

void print_forward(const DNode *head) {
    const DNode *p = head;
    while (p != NULL) {
        printf("%d", p->val);
        if (p->next != NULL) printf(" <-> ");
        p = p->next;
    }
    printf("\n");
} 
void print_backward(const DNode *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    const DNode *tail = head;
    while (tail->next != NULL) tail = tail->next;
    const DNode *p = tail;
    while (p != NULL) {
        printf("%d", p->val);
        if (p->prev != NULL) printf(" <-> ");
        p = p->prev;
    }
    printf("\n");
}


void free_list(DNode *head) {
    DNode *tmp;
    while (head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main(void) {
    DNode *head = NULL;
    int values[] = {3, 1, 4, 2, 5, 0, 3};
    size_t n = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < n; ++i) {
        head = insert_sorted(head, values[i]);
        printf("Après insertion de %d : ", values[i]);
        print_forward(head);
    }

    printf("Affichage avant -> arrière : ");
    print_forward(head);
    printf("Affichage arrière -> avant : ");
    print_backward(head);

    free_list(head);
    return 0;
}