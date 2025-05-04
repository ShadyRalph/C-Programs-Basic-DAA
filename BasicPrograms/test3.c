#include <stdio.h>
#include <unistd.h>

int main() {
    int i,c=0;
    for(i = 1; i <= 3; ++i) {
       if( fork()==0);
        printf("* ");
        c++;
    }
    printf("\ncount: %d ",c);
    return 0;
}