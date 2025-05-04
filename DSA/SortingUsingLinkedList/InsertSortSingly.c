#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
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

Nod* InsertSort(Nod *head, int sz) {
    if (sz <= 1) {
        return head;
    }
    
    Nod *sorted = NULL;  // Initially, the sorted list is empty
    Nod *current = head; // Current node to be inserted into the sorted list

    while (current != NULL) {
        Nod *next = current->next; // Store the next node before modifying current
        
        // Insert current node into the sorted portion
        if (sorted == NULL || sorted->data >= current->data) {
            ++count;  // Comparison at the head
            current->next = sorted;
            sorted = current;
        } else {
            Nod *temp = sorted;
            
            // Traverse to find the correct position for insertion
            while (temp->next != NULL && temp->next->data < current->data) {
                ++count;  // Count comparison in the loop
                temp = temp->next;
            }
            ++count;  // Final comparison that breaks the loop
            
            // Insert current node after temp
            current->next = temp->next;
            temp->next = current;
        }
        
        // Move to the next node to be sorted
        current = next;
    }

    return sorted;
}
