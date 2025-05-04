#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *forward;
    struct node *back;
} Nod;

int coun(Nod *n);
Nod *getnode(int dat);
void display(Nod *n);
int search(Nod *start,int srch);
void reverse(Nod **start);
void insertbegin(Nod **start, int dat);
void insertend(Nod **start, int dat);
void insertafter(Nod *start, int dat, int afda);
void insertany(Nod **start, int data, int pos);
void deleteend(Nod *start);
Nod *deletebegin(Nod *start);
void deleteAfter(Nod* start, int afda);
void deleteAny(Nod **start, int pos);
void displayreverse(Nod **start);
int main() {
    Nod *head = NULL;
    int ch, data, afda,pos;
    while (1) {
       // printf("Nod= %d, Nod* = %d, Int= %d\n",sizeof(Nod),sizeof(Nod*),sizeof(int));
        printf("1 for insertion at the beginning\n");
        printf("2 for insertion at the end\n");
        printf("3 for insertion at any position\n");
        printf("4 for deletion at the beginning\n");
        printf("5 for deletion at the end\n");
        printf("6 for deletion at any position\n");
        printf("7 for search\n");
        printf("8 for reverse\n");
        printf("9 for display forward\n");
        printf("10 for display backwards\n");
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

        if (ch == 3){
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertany(&head, data, pos);
        }
        if (ch == 4) {
            head=deletebegin(head);
        }
        if (ch == 5) {
            deleteend(head);
        }

        if(ch == 6){
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteAny(&head, pos);
        }
        if(ch == 7){
            printf("Enter the search element: ");
            scanf("%d", &data);
            pos=search(head, data);
            printf("Position: %d\n",pos);
        }
        if (ch == 8) {
            reverse(&head);
        }
        if (ch == 9) {
            display(head);
        }
        if (ch == 10) {
            displayreverse(&head);
        }
    }
}

Nod *getnode(int dat) {
    Nod *new = (Nod *)malloc(sizeof(Nod));
    new->data = dat;
    new->forward= NULL;
    new->back= NULL;
    return new;
}

void display(Nod *n) {
    if (n == NULL){
        printf("The list is Empty!\n");
        return;
    }
    int count = 0;
    Nod* temp=n;
    printf("NULL <-- ");
    while (temp->forward != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->forward;
    }
    printf("%d --> NULL ", temp->data);
    printf("\nTotal nodes: %d\n", coun(n));
}

int coun(Nod *n){
    int coun = 0;
    Nod *nn=n;
    while (nn != NULL) {
        coun++;
        nn = nn->forward;
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
        temp = temp->forward;
    }

}

void reverse(Nod **start) {
    Nod *last = *start, *first=*start;
    int temp;
    while (last->forward != NULL)
       last = last->forward;

    while(last!=first && last->forward!=first){
        temp=last->data;
        last->data=first->data;
        first->data=temp;

        last=last->back;
        first=first->forward;
    }   
}
void displayreverse(Nod **start){
    Nod* temp=*start;
    while (temp->forward != NULL) 
        temp = temp->forward;
    
    printf("NULL <-- ");
    while (temp->back != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->back;
    }
    printf("%d --> NULL ", temp->data);
    printf("\nTotal nodes: %d\n", coun(*start));

}
void insertbegin(Nod **start, int dat) {
    Nod *new = getnode(dat);
    new->forward = *start;
    new->back=NULL;
    if(*start!=NULL)
        (*start)->back=new;
    *start = new;
}

void insertend(Nod **start, int dat) {
    Nod *p = getnode(dat);
    if (*start == NULL) {
        *start = p;
        return;
    }
    while ((*start)->forward != NULL) {
        *start = (*start)->forward;
    }
    p->back=*start;
    (*start)->forward = p;
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
        temp = temp->forward;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->forward = temp->forward;
    newNode->back=temp;
    temp->forward->back=newNode;
    temp->forward = newNode;
}

void deleteend(Nod *start) {
    Nod *temp=start;
    if (start == NULL){
        printf("The list is Empty!\n");
        return;
    }
    if ((start)->forward == NULL) {
        free(start);
        start = NULL;
    } 
    else {
        while (temp->forward != NULL) 
            temp = temp->forward;
        temp->back->forward = NULL;
        free(temp);
    }
}

Nod *deletebegin(Nod *start) {
    if (start == NULL){
        printf("The list is Empty!\n");
        return 0;
    }
    if ((start)->forward == NULL) {
        free(start);
        start = NULL;
        return 0;
    } 
    Nod *temp = start;
    start = (start)->forward;
    start->back=NULL;
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

    Nod* cur = *start;
    int count = 1;
    while (cur != NULL && count < pos) {
        cur = cur->forward;
        count++;
    }

    if (cur == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    if(cur->forward==NULL){
        cur->back->forward=NULL;
        free(cur);
        return; 
    }
    cur->forward->back = cur->back;
    cur->back->forward = cur->forward;
    free(cur);
}