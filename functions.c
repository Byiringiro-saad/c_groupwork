#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char generateToken() {
    srand(time(0));
    int tok1=rand();
    int tok2=rand();
    int tok3=rand();
    sprintf(token,"%d-%d-%d",tok1,tok2,tok3);
    printf("Token : %s",token);
    }

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

void keep_token(){
    char status[50]="Unused";
    token_info.cashpower_no =generateRandomCashNo();
    strcpy(token_info.token,token);
    strcpy(token_info.status,status);
     FILE *fptr;
        fptr = fopen("tokens.csv", "a");

        if (fptr == NULL)
        {
            printf("Failed to open the file.\n");
            exit(-1);
        }
        fwrite(&token_info, sizeof(token), 1, fptr);
        printf("\npayment successfully.\n");
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

void telecom_tower(int money){
    int units;
    if(money<5000){
    printf("Insufficient Balance");
    }else{
    units=money/201;
    printf("\n********************Electric Bill*******************\n");
    printf("Units : %f\n", units);
    generateToken();
    keep_token();
    }
 }

void water_treatment(int money){
    int units;
    if(money<5000){
    printf("Insufficient Balance");
    }else{
    units=money/126;
    printf("\n********************Electric Bill*******************\n");
    printf("Units : %f\n", units);
    generateToken();
    keep_token();
    }
 }

void hotel(int money){
    float units;
    if(money<5000){
    printf("Insufficient Balance");
    }else{
    units=money/157;
     printf("\n********************Electric Bill*******************\n");
    printf("Units : %f\n", units);
    generateToken();
    keep_token();
    }
 }

void health_center(int money){
    float units;
    if(money<5000){
    printf("Insufficient Balance");
    }else{
    units=money/186;
    printf("\n********************Electric Bill*******************\n");
    printf("Units : %f\n", units);
    generateToken();
    keep_token();
    }
 }

void broadcaster(int money){
    float units;
    if(money<5000){
    printf("Insufficient Balance");
    }else{
    units=money/192;
    printf("\n********************Electric Bill*******************\n");
    printf("Units : %f\n", units);
    generateToken();
    keep_token();
    }
 }
 
void data_center(int money){
    float units;
    if(money<5000){
    printf("Insufficient Balance");
    }else{
    units=money/179;
    printf("\n********************Electric Bill*******************\n");
    printf("Units : %f\n", units);
    generateToken();
    keep_token();
    }
}

void residential(){
	float units;
	int ans;
	float ub;       //units before
	float ur;      //units remaining
	float mur;     //money of units remaining
	printf("Have you bought any units before in this month? 1 or 0: ");
	scanf("%d",&ans);
	if(ans==1){
		printf("How many have u bought?  ");
		scanf("%d",&ub);
		if(ub<15){
			ur = 15-ub;
			mur = ur*89;
			if(mur>money){
				units=money/89;
			}
			else{
				units = ur;
				money -=mur;
				if(money<7420){
					units += (money/212);
				}else{
					units = units + 35;
					money -= 7420;
					units += (money/249);
				}
			}
		}
		else{
			if(ub>50){
				ur=50-ub;
				mur = ur*212;
				if(mur>money){
					units=money/212;
				}
				else{
					units = ur;
					money = money-mur;
					units=units+(money/249);
				}
			}
			else{
				units=money/249;
			}
		}
	}else{
		if(money<1335){
			units = (money/89);
		}else{
			units = 15;
			money -= 1335;
			if(money<7420){
				units += (money/212);
			}else{
				units = units + 35;
				money -= 7420;
				units += (money/249);
			}
		}
	}
	printf("You have received %.2f KWH.", units);

}

void checkCategory(char category[]){
   if(!strcmp(category,"residential")){
       residential();
   }
   if(!strcmp(category,"non-residential")){
       printf("execute non-residential function here");
   }
   if(!strcmp(category,"hotel")){
       hotel(money);
       printf("\n************************End********************\n");
   }
   if(!strcmp(category,"telecom tower")){
       telecom_tower(money);
       printf("\n************************End********************\n");
   }
   if(!strcmp(category,"water treatment plant or station")){
       water_treatment(money);
       printf("\n************************End*********************\n");
   }
   if(!strcmp(category,"health facility")){
       health_center(money);
       printf("\n************************End**********************\n");
   }
   if(!strcmp(category,"broadcaster")){
      broadcaster(money);
      printf("\n*************************End**********************\n");
   }
   if(!strcmp(category,"commercial data center")){
       data_center(money);
       printf("\n************************End**********************\n");
   }
}



//Remember call the generateToken() method and keep_token() after giving units to the customer.