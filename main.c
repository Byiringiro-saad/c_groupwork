#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char names[50];
    int cashpower_no;
    char category[50];
    int prev_units;
} Client;

struct token {
   char token[60];
   char status[40];
   int cashpower_no;  
} token_info;

Client customer;
char token[60];
int money;
char token[60];

// Functions are included after the client structure and int money because they will also use them.

#include "functions.c"

int main()
{
    int next_step;
    printf("\n\n<---------------- Welcome to electricity buying system ----------------->\n");
    printf("Choose action:\n1.Register\n2.Buy Electricity\n3.Get All Users\n");
    scanf("%d", &next_step);

    if (next_step == 1)
    {
        registerUser();
    }
    else if (next_step == 2)
    {
        getUserWithCashNo();
        checkCategory(customer.category);
    }
    else if (next_step == 3)
    {
        getAllUsers();
    }
    else
    {
        printf("Invalid choice. Try again.");
        exit(-1);
    }
    return 0;
}
