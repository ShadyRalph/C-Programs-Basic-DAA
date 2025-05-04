#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
}node;

// Function to create a new node with the given data
node *createNode(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node *createLinkedList(int num) {
    if (num == 0) {
        return NULL; 
    }
    node *newNode = createNode(num % 10);
    node *nextNode = createLinkedList(num / 10);
    newNode->next = nextNode;
    return newNode;
}

// Function to print the linked list
void printList(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    node* head = createLinkedList(num);
    printList(head);
    return 0;
}
