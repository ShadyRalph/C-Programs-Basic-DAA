#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Nod;

Nod *createnode(int dat);
void insert(Nod **head, int dat); 
void printlist(Nod *head);
Nod* ImprovBubble(Nod *head, int sz);
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
    head = ImprovBubble(head, sz);
    printlist(head);
    printf("No. of Comparisons: %d\n", count);
    return 0;
}

Nod *createnode(int dat) {
    Nod *new = (Nod*)malloc(sizeof(Nod));
    new->data = dat;
    new->next = NULL;
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
}

void printlist(Nod *head) {
    Nod *temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  
}

Nod* ImprovBubble(Nod *head, int sz) {
    if (sz <= 1) {
        return head;
    }
    Nod *i = NULL, *j = NULL;
    int temp, k,t;
    int bound = sz;
    do {
        i = NULL;
        k = 0;
        t=0;
        for (j = head; j->next != NULL && k < bound - 1; j = j->next, k++) {
            count++; 
            if (j->data > j->next->data) {
                temp = j->next->data;
                j->next->data = j->data;
                j->data = temp;
                i = j;
                t=k;
            }
        }
        if (i != NULL) 
            bound = t+1;
        
    } while (i != NULL);
    
    return head;
}
