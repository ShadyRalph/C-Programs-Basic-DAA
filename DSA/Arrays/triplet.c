#include <stdio.h>
#include <stdlib.h>

typedef struct Triplet {
    int row;
    int col;
    int val;
} trip;

trip* TripMat(int **spar, int row, int col, int size) {
    trip *res = (trip*)malloc(size * sizeof(trip));
    int i, j, k = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (spar[i][j] != 0) {
                res[k].row = i;
                res[k].col = j;
                res[k].val = spar[i][j];
				k++;
            }
        }
    }
    return res;
}

void printTrip(trip *ar, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", ar[i].row, ar[i].col, ar[i].val);
    }
}

int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void inputspar(int** matrix, int row, int col) {
    printf("Enter elements of matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printspar(int** matrix, int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

trip *addTrips(trip *t1, trip *t2,int sz1, int sz2, int *szres){
	int i=0,j=0,k=0;
	trip *res=(trip*) malloc((sz1+sz2)*sizeof(trip));
	while(i<sz1 && j<sz2){
		if(i==sz1 || j==sz2)
			break;
		if(t1[i].row==t2[j].row){
			if(t1[i].col==t2[j].col){
				res[k].row=t1[i].row;
				res[k].col=t1[i].col;
				res[k].val=t1[i].val+t2[j].val;
				i++;
				j++;
				k++;
			}
			else{
				if(t1[i].col<t2[j].col){
					res[k].row=t1[i].row;
					res[k].col=t1[i].col;
					res[k].val=t1[i].val;
					i++;
					k++;
				}
				else{
					res[k].row=t2[j].row;
					res[k].col=t2[j].col;
					res[k].val=t2[j].val;
					j++;
					k++;
				}
			}
		}
		else{
			if(t1[i].row<t2[j].row){
					res[k].row=t1[i].row;
					res[k].col=t1[i].col;
					res[k].val=t1[i].val;
					i++;
					k++;
				}
				else{
					res[k].row=t2[j].row;
					res[k].col=t2[j].col;
					res[k].val=t2[j].val;
					j++;
					k++;
				}
		}
	}
    *szres=k;
	return res;
}

int main() {
    int r1, c1, r2, c2, count=0,coun=0,szsum;
    trip *res,*res1,*sum;
    printf("Enter number of rows and columns for matrix A: ");
    scanf("%d %d", &r1, &c1);
    int** arr1 = allocateMatrix(r1, c1);
    inputspar(arr1, r1, c1);
    printf("\nMatrix A:\n");
    printspar(arr1, r1, c1);

	printf("Enter number of rows and columns for matrix B: ");
    scanf("%d %d", &r2, &c2);
    int** arr2 = allocateMatrix(r2, c2);
    inputspar(arr2, r2,c2);
    printf("\nMatrix B:\n");
    printspar(arr2, r2, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (arr1[i][j] != 0)
                count++;
        }
    }
	for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (arr2[i][j] != 0)
                coun++;
        }
    }
    printf("\nMatrix A:\n");
    res = TripMat(arr1, r1, c1, count);
    printTrip(res, count);
    printf("\nMatrix B:\n");
	res1 = TripMat(arr2, r2, c2, coun);
    printTrip(res1, coun);
    printf("\nSum of the matrices:\n");
	sum=addTrips(res,res1,count,coun,&szsum);
	printTrip(sum,szsum);
    printf("\n");
	return 0;
}


