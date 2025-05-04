#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printOrder(int **s, int i, int j) {
    if (i == j)
        printf("M%d", i); 
    else {
        printf("(");
        printOrder(s, i, s[i][j]);
        printf(" * ");
        printOrder(s, s[i][j] + 1, j);
        printf(")");
    }
}
  
int* inputDimension(int *n) {
    int nm, i, t1, t2, x = 0;
    printf("Enter number of matrices: ");
    scanf("%d", n);
    nm = *n;

    int *p = malloc((nm + 1) * sizeof(int));
    if (!p) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    printf("Enter dimensions for %d matrices in (rows cols) format:\n", nm);
    for (i = 0; i < nm; i++) {
        printf("Matrix %d: ", i);
        scanf("%d %d", &t1, &t2);

        while (t1 == 0 || t2 == 0) {
            printf("Invalid dimension. Please enter again:\n");
            scanf("%d %d", &t1, &t2);
        }

        if (i != 0 && t1 != x) {//first i=0 and t1!=(x=0) which is true there i!=0 is false so at 1st iteration it will never go in this condition
            printf("Invalid matrix chain! Inner dimensions do not match.\n");
            return NULL;// from next iteration if t1 is not equal to the previsous t2 i.e col then only it will cime to this condition
        }

        p[i] = t1;
        x = t2;

        if (i + 1 == nm)
            p[i + 1] = t2;
    }

    return p;
}
void printtable(int **cs, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i < j){
                if(cs[i][j]==INT_MAX)
                    printf("%10s", "∞");
                else
                    printf("%8d", cs[i][j]);

            }
            else if(i==j)
                printf("%8c",'-');
            else
                printf("%8c", 'x');
        }
        printf("\n");
    }
}
int minScalarMuls(int *p, int **m, int **s, int n) {
    int i, j, k, d, q;
    //initialising diagonal elements m[i][i] to 0
    for (i = 0; i < n; i++)
        m[i][i] = 0;
    printtable(m,n);
    for (d = 1; d < n; d++) {
        printf("d=%d\n",d);
        for (i = 0; i < n - d; i++) {
            j = i + d;
            m[i][j] = INT_MAX;
            printf("i=%d\tj=%d+%d=%d\ncost[%d][%d]=%d\n",i,i,k,j,i,j,m[i][j]);
            printf("Cost Table\n");
            printtable(m,n);
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                printf("q=m[%d][%d] + m[%d][%d] + p[%d] * p[%d] * p[%d]=%d\n",i,k,k+1,j,i,k+1,j+1,q);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    printf("Cost Table\n");
                    printtable(m,n);
                    s[i][j] = k;
                    printf("Split Table\n");
                    printtable(s,n);
                    printf("\n");
                }
            }
        }
    }
    return m[0][n - 1];
}
int main() {
    int n = 0, i;
    int *p = inputDimension(&n);
    if (p == NULL) 
        return -1;
    int **c = (int**)malloc(n * sizeof(int *));
    int **s = (int**)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        c[i] = (int *)calloc(n, sizeof(int));
        s[i] = (int *)calloc(n, sizeof(int));
    }
    int minMult = minScalarMuls(p, c, s, n);
    printf("Cost Table\n");
    printtable(c, n);
    printf("Split Table\n");
    printtable(s, n);
    printf("Optimal Parenthesization: ");
    printOrder(s, 0, n - 1);
    printf("\nMinimum scalar matrix multiplication required: %d\n", minMult);
    return 0;
}
