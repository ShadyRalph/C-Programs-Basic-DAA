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
Nod* SelectSort(Nod *head, int sz);
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
    head = SelectSort(head, sz);
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

Nod* SelectSort(Nod* head, int sz) {
    if (sz <= 1) {
        return head;
    }
    typedef Nod* nod;
    nod i=NULL, j=NULL,tail=head,min=NULL;
    int temp;
    while (tail->next!=NULL)
        tail=tail->next;
    int key;
    for (i = head; i != tail; i = i->next) {
        min=i;
        for(j=i->next;j!=NULL;j=j->next){
            if( ++count && j->data<min->data)
                min=j;
        }
        temp=i->data;
        i->data=min->data;
        min->data=temp;
    }
    return head;
}