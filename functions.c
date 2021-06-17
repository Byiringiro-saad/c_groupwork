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
    token_info.cashpower_no = generateRandomCashNo();
    customer.prev_units = 0;

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
            flag = 1;
            break;
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

void broadcaster(int money)
{
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

void data_center(int money)
{
    float units;
    if (money < 5000)
    {
        printf("Insufficient Balance");
    }
    else
    {
        units = money / 179;
        printf("Baught Units : %f", units);
    }
}
void residential()
{
    float units;
    int ans;
    float ub;  //units before
    float ur;  //units remaining
    float mur; //money of units remaining
    printf("Have you bought any units before in this month? 1 or 0: ");
    scanf("%d", &ans);
    if (ans == 1)
    {
        printf("How many have u bought?  ");
        scanf("%d", &ub);
        if (ub < 15)
        {
            ur = 15 - ub;
            mur = ur * 89;
            if (mur > money)
            {
                units = money / 89;
            }
            else
            {
                units = ur;
                money -= mur;
                if (money < 7420)
                {
                    units += (money / 212);
                }
                else
                {
                    units = units + 35;
                    money -= 7420;
                    units += (money / 249);
                }
            }
        }
        else
        {
            if (ub > 50)
            {
                ur = 50 - ub;
                mur = ur * 212;
                if (mur > money)
                {
                    units = money / 212;
                }
                else
                {
                    units = ur;
                    money = money - mur;
                    units = units + (money / 249);
                }
            }
            else
            {
                units = money / 249;
            }
        }
    }
    else
    {
        if (money < 1335)
        {
            units = (money / 89);
        }
        else
        {
            units = 15;
            money -= 1335;
            if (money < 7420)
            {
                units += (money / 212);
            }
            else
            {
                units = units + 35;
                money -= 7420;
                units += (money / 249);
            }
        }
    }
    printf("You have received %.2f KWH.", units);
}
void checkCategory(char category[])
{
    if (!strcmp(category, "residential"))
    {
        residential();
    }
    if (!strcmp(category, "non-residential"))
    {
        printf("execute non-residential function here");
    }
    if (!strcmp(category, "hotel"))
    {
        hotel(money);
    }
    if (!strcmp(category, "telecom tower"))
    {
        telecom_tower(money);
    }
    if (!strcmp(category, "water treatment plant or station"))
    {
        water_treatment(money);
    }
    if (!strcmp(category, "health facility"))
    {
        health_center(money);
    }
    if (!strcmp(category, "broadcaster"))
    {
        broadcaster(money);
    }
    if (!strcmp(category, "commercial data center"))
    {
        data_center(money);
    }
}

void updateUnits(int units)
{
    Client temp_customer;
    FILE *fptr;
    FILE *temp_file;
    fptr = fopen("Clients.csv", "r");
    temp_file = fopen("temp_clients.csv", "w");

    if ((fptr == NULL) || (temp_file == NULL))
    {
        printf("Error while opening files...");
        exit(-1);
    }
    int flag = 0;
    while (fread(&temp_customer, sizeof(Client), 1, fptr))
    {
        if (temp_customer.cashpower_no == customer.cashpower_no)
        {
            printf("Customer meter no are equal\n");
            temp_customer.prev_units = temp_customer.prev_units + units;
            flag = 1;
        }
        fwrite(&temp_customer, sizeof(Client), 1, temp_file);
    }

    fclose(temp_file);
    fclose(fptr);

    if (flag)
    {
        fptr = fopen("Clients.csv", "w");
        temp_file = fopen("temp_clients.csv", "r");
        while (fread(&temp_customer, sizeof(Client), 1, temp_file))
        {
            fwrite(&temp_customer, sizeof(Client), 1, fptr);
        }
        fclose(fptr);
        fclose(temp_file);
    }
}
float non_residential(float amount)
{
    float result;
    int units;
    if (!strcmp(customer.category, "non-residential"))
    {
        if (customer.prev_units == 0)
        {
            if (amount >= 0 && amount <= 22700)
            {
                units = amount / 227;
            }
            else
            {
                result = amount - 22700;
                units = (result / 255) + 100;
            }
        }
        else
        {
            if (customer.prev_units < 100)
            {
                result = (100 - customer.prev_units) * 227;
                if (amount <= result)
                {
                    units = amount / 227;
                }
                else if (amount > result)
                {
                    units = (amount - result) / 255;
                    units += (100 - customer.prev_units);
                }
                else
                {
                    units = 0;
                }
            }
            else if (customer.prev_units >= 100)
            {
                units = amount / 227;
            }
        }
    }
    return units;
}
