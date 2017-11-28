#include<stdio.h>
#include<math.h>

int main(){
    int number = 0;
    int choice;
    int rest;
    int numarray[16]={};
    int i = 0;

    printf("Decimal to Base4 - press 0 \n");
    printf("Base4 to Decimal - press 1 \nand enter: ");
    scanf("%d", &choice);

    if(choice == 0){
        printf("Please type decimal number: ");
        scanf("%d", &number);
        printf("Decimal %d number is in Base4: ", number);
        do{
            rest = number % 4;
            number = number / 4;
            if(rest == 0){
                numarray[i] = "0";
            }else if (rest == 1){
                numarray[i] = "1";
            }else if (rest == 2){
                numarray[i] = "2";
            }else{
                numarray[i] = "3";
            }
            i++;
        }while(number != 0);

        for(i; i>0; i--){
            printf(numarray[i-1]);
        }
        printf("\n");

    }else if (choice == 1){
        printf("Please type (12 digits) Base4 number: ");
        scanf("%d", &number);

        int nDigits = floor(log10(abs(number))) + 1;
        int finNumber=0;

        char str[12];
        sprintf(str, "%d", number);

        for(i; i<nDigits; i++){
            int n = str[i] - '0';
            if(n>=0 && n<=3)
            {
                finNumber = finNumber + (n*pow(4,(nDigits-(i+1))));
            }else{
                printf("Please restart the program. Inserted number is invalid");
                return 0;
            }
        }
        printf("The number is : %d", finNumber);
    }else{
        printf("Please restart the program");
    }
return 0;
}
