#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Nod;

int coun(Nod *n);
Nod *getnode(int dat);
void display(Nod *n);
int search(Nod *start,int srch);
void reverse(Nod **start);
void insertbegin(Nod **start, int dat);
void insertend(Nod **start, int dat) 
void insertafter(Nod *start, int dat, int afda);
void insertany(Nod **start, int data, int pos);
void deleteend(Nod *start);
Nod *deletebegin(Nod *start);
void deleteAfter(Nod* start, int afda);
void deleteAny(Nod **start, int pos);

int main() {
    Nod *head = NULL;
    int ch, data, afda,pos;
    while (1) {
        printf("Nod= %d, Nod* = %d, Int= %d\n",sizeof(Nod),sizeof(Nod*),sizeof(int));
        printf("1 for insertion at the beginning\n");
        printf("2 for insertion at the end\n");
        printf("3 for insertion after a position\n");
        printf("4 for insertion at any position\n");
        printf("5 for deletion at the beginning\n");
        printf("6 for deletion at the end\n");
        printf("7 for deletion after a position\n");
        printf("8 for deletion at any position\n");
        printf("9 for search\n");
        printf("10 for reverse\n");
        printf("11 for display\n");
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
            insertend(head, data);
        }
        if (ch == 3) {
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the number after which insertion must happen: ");
            scanf("%d", &afda);
            insertafter(head, data, afda);
        }
        if (ch==4){
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertany(&head, data, pos);
        }
        if (ch == 5) {
            head=deletebegin(head);
        }
        if (ch == 6) {
            deleteend(head);
        }
        if (ch == 7) {
            printf("Enter the number after which deletion must happen: ");
            scanf("%d",&afda);
            deleteAfter(head, afda);
        }

        if(ch==8){
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteAny(&head, pos);
        }
        if(ch==9){
            printf("Enter the search element: ");
            scanf("%d", &data);
            pos=search(head, data);
            printf("Position: %d\n",pos);
        }
        if (ch == 10) {
            reverse(&head);
        }
        if (ch == 11) {
            display(head);
        }
    }
}

Nod *getnode(int dat) {
    Nod *new = (Nod *)malloc(sizeof(Nod));
    new->data = dat;
    new->next = NULL;
    return new;
}

void display(Nod *n) {
    int count = 0;
    Nod* temp=n;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL ");
    printf("\nTotal nodes: %d\n", coun(n));
}

int coun(Nod *n){
    int coun = 0;
    Nod *nn=n;
    while (nn != NULL) {
        coun++;
        nn = nn->next;
    }
    return coun;
}

int search(Nod *start,int srch){
    Nod* temp=start;
    int count=0;
    while (temp != NULL) {
        count++;
        if(temp->data==srch){
            return count;
        }
        temp = temp->next;
    }

}

void reverse(Nod **start) {
    Nod *back = NULL;
    Nod *cur = *start;
    Nod *front = NULL;

    while (cur != NULL) {
        front = cur->next;
        cur->next = back;  
        back = cur;       
        cur = front;      
    }
    *start = back;// setting head to the current node
}

void insertbegin(Nod **start, int dat) {
    Nod *new = getnode(dat);
    new->next = *start;
    *start = new;
}

void insertend(Nod **start, int dat) {
    Nod *p = getnode(dat);
    if (*start == NULL) {
        *start = p;
        return;
    }
    while (*start->next != NULL) {
        *start = *start->next;
    }
    *start->next = p;
}

void insertafter(Nod *start, int dat, int afda) {
    Nod *new = getnode(dat);
    Nod *front, *back = start;
    if (start == NULL) {
        free(new);
        return;
    } else {
        while (back->data != afda && back->next != NULL)
            back = back->next;
        if (back->data == afda) {
            front = back->next;
            back->next = new;
            new->next = front;
        } else {
            free(new);
            return;
        }
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

    Nod* newNode = getnode(data);
    Nod* temp = *start;
    int count = 1;
    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteend(Nod *start) {
    Nod *front = start, *back;
    if (start == NULL)
        return;
    if ((start)->next == NULL) {
        free(start);
        start = NULL;
    } else {
        while (front->next != NULL) {
            back = front;
            front = front->next;
        }
        free(front);
        back->next = NULL;
    }
}

Nod *deletebegin(Nod *start) {
    if (start == NULL)
        return 0;
    Nod *temp = start;
    start = (start)->next;
    free(temp);
    return start;
}

void deleteAfter(Nod* start, int afda) {
    Nod* current = start;
    while (current != NULL && current->data != afda) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        return;
    }
    Nod* temp = current->next;
    current->next = temp->next;
    free(temp);
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

    Nod* temp = *start;
    Nod* prev = NULL;
    int count = 1;
    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}