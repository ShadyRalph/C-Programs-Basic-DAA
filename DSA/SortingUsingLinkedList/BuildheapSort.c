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
Nod* HeapSort(Nod *head, int sz);
void heapify(Nod *head, int sz);
void adjust(Nod *head, int i, int sz);
Nod* getNodeAt(Nod *head, int index);

static int count = 0;  

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
    head = HeapSort(head, sz);
    printlist(head);
    printf("No. of Comparisons: %d\n", count);
    return 0;
}

Nod *createnode(int dat) {
    Nod *new = (Nod*)malloc(sizeof(Nod));
    new->data = dat;
    new->next = NULL;
    new->prev = NULL;
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

Nod* getNodeAt(Nod *head, int index) {
    Nod *current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

void adjust(Nod *head, int i, int sz) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int lar = i;
    
    Nod *node_i = getNodeAt(head, i);
    Nod *node_l = getNodeAt(head, l);
    Nod *node_r = getNodeAt(head, r);
    
    count++;
    if (l < sz && node_l != NULL && node_l->data > node_i->data) {
        lar = l;
    }

    count++;
    if (r < sz && node_r != NULL && node_r->data > getNodeAt(head, lar)->data) {
        lar = r;
    }
    
    if (lar != i) {
        // Swap the values
        Nod *node_lar = getNodeAt(head, lar);
        int temp = node_i->data;
        node_i->data = node_lar->data;
        node_lar->data = temp;

        adjust(head, lar, sz);
    }
}

void heapify(Nod *head, int sz) {
    for (int i = (sz - 2) / 2; i >= 0; i--) {
        adjust(head, i, sz);
    }
}

Nod* HeapSort(Nod* head, int sz) {
    if (sz <= 1) {
        return head;
    }
    heapify(head, sz);
    count = 0;
    
    for (int i = sz - 1; i > 0; i--) {
        Nod *node_0 = getNodeAt(head, 0);
        Nod *node_i = getNodeAt(head, i);
        int temp = node_0->data;
        node_0->data = node_i->data;
        node_i->data = temp;
        adjust(head, 0, i);
    }
    return head;
}
