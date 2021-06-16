#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generate_token();
int main()
{
 generate_token();  
}
int generate_token(){
   srand(time(0));
     printf("Token is %d-%d-%d",rand());
    return 0;
}