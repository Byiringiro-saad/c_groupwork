#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generateRandomCashNo()
{
    srand(time(NULL));
    int low1 = 9869000;
    int high1 = 98900000;
    int low2 = 500;
    int high2 = 1000;
    int cashpower1 = (rand() % (high1 - low1 + 1)) + low1;
    int cashpower2 = (rand() % (high2 - low2 + 1)) + low2;
    return cashpower1 + cashpower2;
}

void registerUser(){
    int category;
        printf("Names: ");
        fflush(stdin);
        fgets(customer.names, 49, stdin);
        printf("Choose category: \n");
        printf("1.Residential\n2.Non-residential\n3.Telecom Tower\n4.Water treament plant or station\n");
        printf("5.Hotel\n6.Health Facility\n7.Broadcaster\n8.Commercial data center\n");
        scanf("%d", &category);

        switch (category)
        {
        case 1:
            strcpy(customer.category, "residential");
            break;
        case 2:
            strcpy(customer.category, "non-residential");
            break;
        case 3:
            strcpy(customer.category, "telecom tower");
            break;
        case 4:
            strcpy(customer.category, "water treatment plant or station");
            break;
        case 5:
            strcpy(customer.category, "hotel");
            break;
        case 6:
            strcpy(customer.category, "health facility");
            break;
        case 7:
            strcpy(customer.category, "broadcaster");
            break;
        case 8:
            strcpy(customer.category, "commercial data center");
            break;

        default:
            printf("Invalid choice please try again.");
            exit(-1);
            break;
        }

        customer.cashpower_no = generateRandomCashNo();
        customer.prev_units = 10;

        printf("Names: %s", customer.names);
        printf("meter no: %d\n", customer.cashpower_no);
        printf("category: %s\n", customer.category);
        printf("Units: %d\n", customer.prev_units);

        FILE *fptr;
        fptr = fopen("Clients.csv", "a");

        if (fptr == NULL)
        {
            printf("Failed to open the file.\n");
            exit(-1);
        }
        fwrite(&customer, sizeof(Client), 1, fptr);
        printf("User registration completed.\n");
}

void getAllUsers(){
    FILE *fptr;
    fptr = fopen("Clients.csv", "r");

    if (fptr == NULL)
    {
        printf("Failed to open the file.\n");
        exit(-1);
    }
        int d = 1;
    while (fread(&customer, sizeof(Client), 1, fptr))
    {
        printf("User %d\n", d);
        printf("Name: %sCashPower: %d \nCategory: %s \n", customer.names, customer.cashpower_no, customer.category);
        d++;
    }
}

void getUserWithCashNo(){
    int meter_no;
        printf("Enter meter no: ");
        scanf("%d", &meter_no);
        printf("Enter Amount: ");
        scanf("%d", &money);

        FILE *fptr;
        fptr = fopen("Clients.csv", "r");

        if (fptr == NULL)
        {
            printf("Failed to open the file.\n");
            exit(-1);
        }

        int flag = 0;
        while (fread(&customer, sizeof(Client), 1, fptr))
        {
            
            if(customer.cashpower_no==meter_no){
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("Invalid meter number. Try again.");
            exit(-1);
        }

        int proceed=0;
        printf("You have entered %d meter number which is for %s\n1.Continue\n0.Exit\n", customer.cashpower_no,customer.names);
        scanf("%d", &proceed);
        if(!proceed){
            printf("Exiting....");
            exit(-1);
        }
}


void checkCategory(char category[]){
   if(!strcmp(category,"residential")){
       printf("execute Residential function here");
   }
   if(!strcmp(category,"non-residential")){
       printf("execute non-residential function here");
   }
   if(!strcmp(category,"hotel")){
       printf("execute hotel function here");
   }
   if(!strcmp(category,"telecom tower")){
       printf("execute telecom tower function here");
   }
   if(!strcmp(category,"water treatment plant or station")){
       printf("execute water treatment plant or station function here");
   }
   if(!strcmp(category,"health facility")){
       printf("execute health facility function here");
   }
   if(!strcmp(category,"broadcaster")){
       printf("execute broadcaster function here");
   }
   if(!strcmp(category,"commercial data center")){
       printf("execute commercial data center function here");
   }
}
