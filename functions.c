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

void registerUser()
{
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
        token_info.cashpower_no =generateRandomCashNo();
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

void getAllUsers()
{
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
        printf("Name: %sCashPower: %d \nCategory: %s \nUnits: %d\n", customer.names, customer.cashpower_no, customer.category, customer.prev_units);
        d++;
    }
}

void getUserWithCashNo()
{
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

        if (customer.cashpower_no == meter_no)
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
    }
    if (!flag)
    {
        printf("Invalid meter number. Try again.");
        exit(-1);
    }

    int proceed = 0;
    printf("You have entered %d meter number which is for %s\n1.Continue\n0.Exit\n", customer.cashpower_no, customer.names);
    scanf("%d", &proceed);
    if (!proceed)
    {
        printf("Exiting....");
        exit(-1);
    }
}

void telecom_tower(int money)
{
    int units;
    if (money < 5000)
    {
        printf("Insufficient Balance");
    }
    else
    {
        units = money / 201;
        printf("You have Baught %d Units", units);
    }
    return 0;
}

void water_treatment(int money)
{
    int units;
    if (money < 5000)
    {
        printf("Insufficient Balance");
    }
    else
    {
        units = money / 126;
        printf("You have Baught %d Units", units);
    }
    return 0;
}

void hotel(int money)
{
    float units;
    if (money < 5000)
    {
        printf("Insufficient Balance");
    }
    else
    {
        units = money / 157;
        printf("Baught Units : %f", units);
    }
}

void health_center(int money)
{
    float units;
    if (money < 5000)
    {
        printf("Insufficient Balance");
    }
    else
    {
        units = money / 186;
        printf("Baught Units : %f", units);
    }
    return 0;
}

void broadcaster(int money){
    float units;
    if(money<5000){
    printf("Insufficient Balance");
    }else{
    units=money/192;
    printf("Baught  Units : %f", units);
    }
 }

void data_center(int money){
    float units;
    if (money < 5000)
    {
        printf("Insufficient Balance");
    }
    else
    {
        units = money / 192;
        printf("Baught  Units : %f", units);
    }
}

void checkCategory(char category[]){
   if(!strcmp(category,"residential")){
       residential();
   }
   if(!strcmp(category,"non-residential")){
       int saad = non_residential(money);
       printf("\n%d", saad);
   }
   if(!strcmp(category,"hotel")){
       hotel(money);
   }
   if(!strcmp(category,"telecom tower")){
       telecom_tower(money);
   }
   if(!strcmp(category,"water treatment plant or station")){
       water_treatment(money);
   }
   if(!strcmp(category,"health facility")){
       health_center(money);
   }
   if(!strcmp(category,"broadcaster")){
      broadcaster(money);
   }
   if(!strcmp(category,"commercial data center")){
       data_center(money);
   }
}
int non_residential(int amount) {
    int money;
  	int result;
  	int units;
    if(customer.prev_units > 0){
        if(amount >= 0 && amount <= 22700){
            units = 100;
            money = amount - 22700;
            return units = units + (money / 225);
        }else{
            return units = amount / 227;
        }
    }else{
	  	if(customer.prev_units < 100){
	  		if(customer.prev_units < 100){
                result = 100 - customer.prev_units;
                money = result * 227;

                if(money > amount){
                    return units = amount / 277;
                }else{
                    units = result;
                    amount = amount - money;
                    return units = units + ( amount / 255 );
                }
	  		}
	  }else{
        return units = amount - 255;
	  }
  }
  return units;
}
