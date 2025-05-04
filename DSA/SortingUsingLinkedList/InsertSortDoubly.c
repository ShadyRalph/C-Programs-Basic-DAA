#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Nod;

Nod *createnode(int dat);
void insert(Nod **head, int dat); 
void printlist(Nod *head);
Nod* InsertSort(Nod *head, int sz);
static int count = 0;  // Global variable to count comparisons

int main() {
    int sz, i, data;
    Nod *head = NULL;
    
    printf("Enter the size: ");
    scanf("%d", &sz);
    
    printf("Enter the elements: \n");
    for (i = 0; i < sz; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original List: \n");
    printlist(head);

    printf("After sorting: \n");
    head = InsertSort(head, sz);
    printlist(head);
    printf("No. of Comparisons: %d\n", count);
    return 0;
}

Nod *createnode(int dat) {
    Nod *new = (Nod*)malloc(sizeof(Nod));
    new->data = dat;
    new->next = NULL;
    new->prev=NULL;
    return new;
}

void insert(Nod **head, int dat) {
    Nod* new = createnode(dat);
    if (*head == NULL) {
        *head = new;
        return;
    }
    Nod *tail = *head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = new;
    new->prev = tail;
}

void printlist(Nod *head) {
    Nod *temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  
}

Nod* InsertSort(Nod* head, int sz) {
    if (sz <= 1) {
        return head;
    }
    typedef Nod* nod;
    nod i, j;
    int key;
    for (i = head->next; i != NULL; i = i->next) {
        key = i->data;
        j = i->prev;
        while (j != NULL && ++count && j->data > key ) {
            j->next->data = j->data;
            j = j->prev;
        }
        if (j == NULL) {
            head->data = key;  // Insert at the head if j reaches NULL
        } else {
            j->next->data = key;
        }
    }
    return head;
}

