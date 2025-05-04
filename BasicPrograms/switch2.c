#include <stdio.h>
// conditional switch operator
void main(){
char day;
printf("Enter day: ");
scanf("%c",&day);
// for character input use %s
switch (day)
{
case 'M': printf("monday");
    break;
case 'T': printf("tuesday");
    break;
case 'W': printf("wednesday");
    break;
case 't': printf("thursday");
    break;
case 'F': printf("friday");
    break;
case 's': printf("saturday");
    break;
case 'S': printf("sunday");
    break;
    
default: printf("not valid");
}
}