#include <stdio.h>
// conditional switch operator
void main(){
int day;
printf("Enter day b/w 1-7: ");
scanf("%d",&day);

switch (day)
{
case 1: printf_s("monday");
    break;
case 2: printf_s("tuesday");
    break;
case 3: printf_s("wednesday");
    break;
case 4: printf_s("thursday");
    break;
case 5: printf_s("friday");
    break;
case 6: printf_s("saturday");
    break;
case 7: printf_s("sunday");
    break;
    
default: printf_s("not valid");
}
}

