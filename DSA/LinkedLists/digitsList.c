#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
typedef struct Node {
    int data;
    struct Node* next;
}node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from the digits of a number
node* createDigitList(int n) {
    if (n == 0) {
        return createNode(0);
    }

    struct Node *head = NULL, *tail = NULL;
    int digits[10]; // Temporary array to store digits
    int count = 0;
    while (n > 0) {
        digits[count++] = n % 10;
        n= n/10;
    }
    
    for (int i = count - 1; i >= 0; i--) {
        node* newNode = createNode(digits[i]);
        if (head == NULL) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

// Function to print the linked list
void printList(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    int num = 13579;
    node* head = createDigitList(num);
    printList(head);
    return 0;
}
