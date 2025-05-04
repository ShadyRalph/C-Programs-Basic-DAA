#include <stdio.h>
void hanoi(int n,char s, char t, char d){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",s,d);
        return;
    }
    hanoi(n-1,s,d,t);
    printf("Move disk %d from %c to %c\n",n,s,d);
    hanoi(n-1,t,s,d);
}
int main(){
    int n;
    printf("Enter the no. of disks: ");
    scanf("%d",&n);
    hanoi(n,'S','T','D');
    return 0;
}