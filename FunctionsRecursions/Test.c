#include <stdio.h>
void recall1();//have to declare these functions before calling in main
void recall2();
int main()
{
recall1();
recall2();
printf("Brad: Nah... nothing much \n");
return 0;
}
void recall1()
{
printf("Yo Mate... \n");
}

void recall2()
{
  printf("what's up \n");
}
