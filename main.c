#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> //Sleep() ve system("CLS") fonksiyonlarý için kullanýldý
#include <conio.h>

int Fibonacci(int x);

int main(int argc, char *argv[]) {
	int programNo;
	int i, j, flag, number=3, rank=2; //Program No:1 variables
	char selection;	//Program No:1 variables
	int sayi1, sayi2, secim, kucukOlanSayi, buyukOlanSayi, ebob, ekok; //Program No:2 variables
	int secim3; //Program No:3 variables

	printf(" ==========SEZGIN ERPAYTONCU==========\n =====================================\n\n Please enter the program that you want to run...\n");
	printf(" 1.Prime Number Generator\n 2.Finding Greatest Common Divisor & Smallest Common Multiple\n 3.Fibonacci Numbers\n ");
	scanf("%d", &programNo);

	switch(programNo){
		case 1: //Prime Number Generator
			system("CLS");
			fflush(stdin);
			printf(" \nPlease press ENTER to see the next prime number...\n If you want to QUIT the program, please enter \"Q\"...\n\n 1. Prime Number: 2\n");
			scanf("%c", &selection);
			while(selection!='Q' || selection!='q'){
				
				if(selection=='Q' || selection=='q')
					break;
				do{		//The "do-while" loop continues until it finds the next prime number	
					flag=0;
					//prime number control loop
					for(j=2;j<number;j++){ //If the number variable is not prime, flag=1
						if(number%j==0){ 
							flag=1;
							break;
						}
					}
					if(flag==0){
						printf(" %d. Prime Number: %d\n", rank, number);
						rank++;
					}
					number++;
				}while(flag!=0);
				scanf("%c", &selection);
			}
			break; //End of Program No:1
	
		case 2: //GCD and SCM
			while(1){
				printf(" \n Please select an action...\n 1.Finding greatest common divisor\n 2.Finding smallest common multiple\n 3.Exit\n");
				scanf("%d", &secim);
				if(secim==1||secim==2){
					printf(" Please enter the first number...\n");
					scanf("%d", &sayi1);
					printf(" Please enter the second number...\n");
					scanf("%d", &sayi2);
					if(sayi1<=sayi2){ //EBOB-EKOK bulma iþlemi için, for döngüsünde kucuk olan sayýyý bilmeye ihtiyac vardýr. Sayýlar eþitse önemli deðil...
						kucukOlanSayi=sayi1;
						buyukOlanSayi=sayi2;
					}
					else{
						kucukOlanSayi=sayi2;
						buyukOlanSayi=sayi1;
					}
					switch(secim){
						case 1: //EBOB Bulma
							for(i=1;i<=kucukOlanSayi;i++){
								if(sayi1%i==0 && sayi2%i==0)
									ebob=i;
							}
							printf(" \nThe greatest divisor of %d and %d is %d\n",sayi1,sayi2,ebob);
							getch();
							fflush(stdin);
							break;
						case 2: //EKOK Bulma
							//int i=buyukOlanSayi;
							do{
								if(i%sayi1==0 && i%sayi2==0){
									ekok=i;
									break;
								}
							}while(1);
							/*Alternatif Yol
							sayi1*sayi2=ebob*ekok
							ekok=(sayi1*sayi2)/ebob(sayi1,sayi2);*/
							printf(" \nThe smallest common multiple of %d and %d is %d\n",sayi1,sayi2,ekok);
							break;
					}
				}
					else if(secim==3)
						break;
					else{
						printf(" Yanlis giris yaptiniz.Lutfen tekrar deneyiniz...\n");
						continue;
					}
				
			}
			break; //End of Program No:2
		
		case 3: //Fibonacci
			printf(" Please enter which Fibonacci number that you want to see...\n If you want to QUIT the program, please enter \"0 (ZERO)\"...\n");
			scanf("%d", &secim3);
			/*if(selection=='Q'||selection=='q')
				break;*/
			while(secim3!=0){
				printf(" %d. Fibonacci Number: %d\n",secim3,Fibonacci(secim3));
				scanf("%d", &secim3);
			}
			break; //End of Program No:3
			
		case 4: //Mirror of the entered number
			
			break; //End of Program No:4
		default:
			printf("You have entered an incorrect value...\n");
	}
	printf("\n Exiting from the program...\n");
	Sleep(1000);
	printf("\n ©Sezgin Erpaytoncu\n");
	Sleep(2000);
	return 0;
}

int Fibonacci(int x){
	int result;	
	if(x==1 || x==2)
		return 1;
	result = Fibonacci(x-1)+Fibonacci(x-2);
	return result;
}
