#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int cof;
    int exp;
    struct node *next;
} Nod;

Nod *getnode(int coef, int expo);
void display(Nod *n);
void insertbegin(Nod **start, int coef, int expo);
void deleteend(Nod **start);
Nod *deletebegin(Nod *start);
void deleteAny(Nod **start, int pos);
Nod *addition(Nod* head1, Nod* head2);

int main() {
    Nod *head1 = NULL, *head2 = NULL, *head3 = NULL;
    int ch1, ch2, exp, coef, pos;

    while (1) {
        printf("1 for creation of polynomial 1 \n");
        printf("2 for creation of polynomial 2 \n");
        printf("3 for addition of the two polynomials \n");
        printf("0 for exit\n");
        printf("Enter: ");
        scanf("%d", &ch2);
        if (ch2 == 0)
            return 0;
        if (ch2 == 1) {
            while (1) {
                printf("1 for insertion\n");
                printf("2 for deletion at the beginning\n");
                printf("3 for deletion at the end\n");
                printf("4 for deletion at any position\n");
                printf("5 for display\n");
                printf("0 to skip\n");
                printf("Enter: ");
                scanf("%d", &ch1);
                if (ch1 == 0)
                    break;
                if (ch1 == 1) {
                    printf("Enter coefficient: ");
                    scanf("%d", &coef);
                    printf("Enter exponent: ");
                    scanf("%d", &exp);
                    insertbegin(&head1, coef, exp);
                }
                if (ch1 == 2) {
                    head1 = deletebegin(head1);
                }
                if (ch1 == 3) {
                    deleteend(&head1);
                }
                if (ch1 == 4) {
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    deleteAny(&head1, pos);
                }
                if (ch1 == 5) {
                    printf("Polynomial 1: \n");
                    display(head1);
                }
            }
        }
        if (ch2 == 2) {
            while (1) {
                printf("1 for insertion\n");
                printf("2 for deletion at the beginning\n");
                printf("3 for deletion at the end\n");
                printf("4 for deletion at any position\n");
                printf("5 for display\n");
                printf("0 to skip\n");
                scanf("%d", &ch1);
                if (ch1 == 0)
                    break;
                if (ch1 == 1) {
                    printf("Enter coefficient: ");
                    scanf("%d", &coef);
                    printf("Enter exponent: ");
                    scanf("%d", &exp);
                    insertbegin(&head2, coef, exp);
                }
                if (ch1 == 2) {
                    head2 = deletebegin(head2);
                }
                if (ch1 == 3) {
                    deleteend(&head2);
                }
                if (ch1 == 4) {
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    deleteAny(&head2, pos);
                }
                if (ch1 == 5) {
                    printf("Polynomial 2: \n");
                    display(head2);
                }
            }
        }
        if (ch2 == 3) {
            head3 = addition(head1, head2);
            printf("Resulting Polynomial: \n");
            display(head3);
        }
    }
}

Nod *getnode(int coef, int expo) {
    Nod *new = (Nod *)malloc(sizeof(Nod));
    new->cof = coef;
    new->exp = expo;
    new->next = NULL;
    return new;
}

void display(Nod *n) {
    if (n == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    while (n != NULL) {
        if(n->cof==0)
            printf("0");
        else if(n->exp==0)
            printf("%d",n->cof);
        else if(n->exp==1)
            printf("%dx",n->cof);    
        else
            printf("%dx^%d", n->cof, n->exp);
        
        if (n->next != NULL)
            printf(" + ");
        n = n->next;
    }
    printf("\n");
}

void insertbegin(Nod **start, int coef, int expo) {
    Nod *new = getnode(coef, expo);
    new->next = *start;
    *start = new;
}

void deleteend(Nod **start) {
    if (*start == NULL)
        return;
    if ((*start)->next == NULL) {
        free(*start);
        *start = NULL;
    } else {
        Nod *front = *start, *back = NULL;
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
        return NULL;
    Nod *temp = start;
    start = start->next;
    free(temp);
    return start;
}

void deleteAny(Nod **start, int pos) {
    if (pos < 1 || *start == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        *start = deletebegin(*start);
        return;
    }
    Nod *temp = *start, *prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

Nod* addition(Nod* head1, Nod* head2) {
    Nod *head3 = NULL;
    Nod *p1 = head1, *p2;
    int coef, expo;

    while (p1 != NULL) {
        p2 = head2;
        while (p2 != NULL) {
            if (p1->exp == p2->exp) {
                coef = p1->cof + p2->cof;
                expo = p1->exp;
                break;
            }
            p2 = p2->next;
        }
        if (p2 == NULL) {
            coef = p1->cof;
            expo = p1->exp;
        }
        insertbegin(&head3, coef, expo);
        p1 = p1->next;
    }
    p2 = head2;
    while (p2 != NULL) {
        Nod *p3 = head3;
        int k = 0;
        while (p3 != NULL) {
            if (p3->exp == p2->exp) {
                k = 1;
                break;
            }
            p3 = p3->next;
        }
        if (k==0) {
            insertbegin(&head3, p2->cof, p2->exp);
        }
        p2 = p2->next;
    }
    return head3;
}


