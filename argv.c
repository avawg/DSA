/*
* argv.c
*/
#include <stdio.h>
int main(int narg,char **args)
{
   if ( narg != 2 )  {
       printf("error,the input parameter must be one!\n");
       return -1;
   }
   char *str = args[1];
   printf("the input parameter is %s\n",str);
   return 0;
}