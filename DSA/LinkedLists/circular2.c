#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Nod;

int coun(Nod *n);
Nod *getnode(int dat);
void display(Nod *n);
int search(Nod *start, int srch);
void reverse(Nod **start);
void insertbegin(Nod **start, int dat);
void insertend(Nod **start, int dat);
void insertany(Nod **start, int data, int pos);
void deleteend(Nod **start);
Nod *deletebegin(Nod *start);
void deleteAny(Nod **start, int pos);

int main() {
    Nod *head = NULL;
    int ch, data, pos;
    while (1) {
        printf("1 for insertion at the beginning\n");
        printf("2 for insertion at the end\n");
        printf("3 for insertion at any position\n");
        printf("4 for deletion at the beginning\n");
        printf("5 for deletion at the end\n");
        printf("6 for deletion at any position\n");
        printf("7 for search\n");
        printf("8 for reverse\n");
        printf("9 for display\n");
        printf("0 for exit\n");
        printf("Enter: ");
        scanf("%d", &ch);
        if (ch == 0)
            return 0;
        if (ch == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            insertbegin(&head, data);
        }
        if (ch == 2) {
            printf("Enter data: ");
            scanf("%d", &data);
            insertend(&head, data);
        }
        if (ch == 3) {
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertany(&head, data, pos);
        }
        if (ch == 4) {
            head = deletebegin(head);
        }
        if (ch == 5) {
            deleteend(&head);
        }
        if (ch == 6) {
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteAny(&head, pos);
        }
        if (ch == 7) {
            printf("Enter the search element: ");
            scanf("%d", &data);
            pos = search(head, data);
            printf("Position: %d\n", pos);
        }
        if (ch == 8) {
            reverse(&head);
        }
        if (ch == 9) {
            display(head);
        }
    }
}

Nod *getnode(int dat) {
    Nod *new = (Nod *)malloc(sizeof(Nod));
    new->data = dat;
    new->next = new;
    return new;
}

void display(Nod *n) {
    if (n == NULL) {
        printf("List is empty.\n");
        return;
    }

    Nod *temp = n;
    do {
        printf(" %d -->", temp->data);
        temp = temp->next;
    } while (temp != n);
    printf("> %d(head)\n",temp->data);
    printf("Total nodes: %d\n", coun(n));
}

int coun(Nod *n) {
    if (n == NULL)
        return 0;
    
    int count = 0;
    Nod *temp = n;
    do {
        count++;
        temp = temp->next;
    } while (temp != n);
    return count;
}

int search(Nod *start, int srch) {
    if (start == NULL)
        return -1;

    Nod *temp = start;
    int pos = 1;

    do {
        if (temp->data == srch)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != start);

    return -1;  // If not found
}

void reverse(Nod **start) {
    if (*start == NULL || (*start)->next == *start)
        return;

    Nod *prev = NULL, *cur = *start, *next;
    Nod *last = *start;

    do {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } while (cur != *start);

    last->next = prev;
    *start = prev;
}

void insertbegin(Nod **start, int dat) {
    Nod *new = getnode(dat);
    if (*start == NULL) {
        new->next = new;
        *start = new;
    } else {
        Nod *tail = *start;
        while (tail->next != *start) {
            tail = tail->next;
        }
        new->next = *start;
        tail->next = new;
        *start = new;
    }
}

void insertend(Nod **start, int dat) {
    Nod *new = getnode(dat);
    if (*start == NULL) {
        new->next = new;
        *start = new;
    } else {
        Nod *tail = *start;
        while (tail->next != *start) {
            tail = tail->next;
        }
        tail->next = new;
        new->next = *start;
    }
}

void insertany(Nod **start, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertbegin(start, data);
        return;
    }

    Nod *newNode = getnode(data);
    Nod *temp = *start;
    int count = 1;
    while (count < pos - 1 && temp->next != *start) {
        temp = temp->next;
        count++;
    }

    if (count < pos - 1) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteend(Nod **start) {
    if (*start == NULL)
        return;

    Nod *tail = *start, *prev = NULL;

    if (tail->next == *start) {  // Only one node
        free(tail);
        *start = NULL;
        return;
    }

    while (tail->next != *start) {
        prev = tail;
        tail = tail->next;
    }

    prev->next = *start;
    free(tail);
}

Nod *deletebegin(Nod *start) {
    if (start == NULL)
        return NULL;

    Nod *tail = start;
    while (tail->next != start) {
        tail = tail->next;
    }

    if (start->next == start) {  // Only one node
        free(start);
        return NULL;
    }

    Nod *temp = start;
    start = start->next;
    tail->next = start;
    free(temp);

    return start;
}

void deleteAny(Nod **start, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        *start = deletebegin(*start);
        return;
    }

    Nod *temp = *start, *prev = NULL;
    int count = 1;
    while (count < pos && temp->next != *start) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < pos) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
