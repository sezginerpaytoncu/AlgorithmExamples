#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> //Sleep() ve system("CLS") fonksiyonlarý için kullanýldý
#include <conio.h>
#include <string.h> //Used for strlen function in MirrorNumber

int Fibonacci(int x);
void MirrorNumber(char *number);

int main(int argc, char *argv[]) {
	int programNo;
	int i, j, flag, number=3, rank=2; //Program No:1 variables
	char selection;	//Program No:1 variables
	int k, sayi1, sayi2, secim, kucukOlanSayi, buyukOlanSayi, ebob, ekok; //Program No:2 variables
	int secim3; //Program No:3 variables
	char number4[10]; int inputNumber; //Program No:4 variables
	//int number5, p, geciciSayi, basamakSayisi=0, basamaklar[basamakSayisi]; // Alternative Program No:4 variables

	while(programNo!=5){
		system("CLS");
		printf(" =====================================\n ==========SEZGIN ERPAYTONCU==========\n =====================================\n\n Please enter the program that you want to run...\n");
		printf(" 1.Prime Number Generator\n 2.Finding Greatest Common Divisor & Smallest Common Multiple\n 3.Fibonacci Numbers\n 4.Mirror of Entered Number\n 5.Exit\n\n");
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
					system("CLS");
					fflush(stdin);
					printf(" \n Please select an action...\n 1.Finding greatest common divisor\n 2.Finding smallest common multiple\n 3.EXIT\n");
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
							case 1: //Finding GCD / EBOB Bulma
								for(i=1;i<=kucukOlanSayi;i++){
									if(sayi1%i==0 && sayi2%i==0)
										ebob=i;
								}
								printf("\n The greatest divisor of %d and %d is %d\n",sayi1,sayi2,ebob);
								break;
							case 2: //Finding SCM / EKOK Bulma
								k=buyukOlanSayi;
								do{
									if(k%sayi1==0 && k%sayi2==0){
										ekok=k;
										break;
									}
									k++;
								}while(1);
								/*	//Alternatif EBOB Bulma Yolu
								sayi1*sayi2=ebob*ekok
								ekok=(sayi1*sayi2)/ebob(sayi1,sayi2);*/
								printf("\n The smallest common multiple of %d and %d is %d\n",sayi1,sayi2,ekok);
								break;
						}
						getch();
						fflush(stdin);
					}
					else if(secim==3)
						break;
					else{
						printf(" You have entered an incorrect value.Please try again...\n");
						continue;
					}	
				}
				break; //End of Program No:2
			
			case 3: //Fibonacci
				system("CLS");
				fflush(stdin);
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
				system("CLS");
				fflush(stdin);
				printf(" Please enter the number that you want to see mirrored...\n");
				scanf("%s", number4); //gets ile ayný
				printf(" Your number: %s\n", number4);
				MirrorNumber(number4);
				printf(" Mirrored number: %s\n", number4);
				
				/* Alternatif2
				scanf("%d", &number5);
				geciciSayi=number5;
				while(1){
					if(geciciSayi==0)
						break;
				basamakSayisi++;
				geciciSayi/=10;		
				}
				for(p=0;p<basamakSayisi;p++){
					basamaklar[p]=number5%10;
					number5=number5/10;
				}
				//printf("%d\n", basamakSayisi);
				for(p=0;p<basamakSayisi;p++){
					printf("%d", basamaklar[p]);
				}*/
				getch();
				break; //End of Program No:4
			case 5:
				programNo=5;
				break;
			default:
				printf("You have entered an incorrect value...\n");
				getch();
				break;
		}
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

void MirrorNumber(char *number){
	int i, size;
	char temporary[10];
	//size=sizeof(number); //gelen array 10 elemanlý oluþturulmuþtu. Yani 8 element ve en of string "\0" içeriyor. Bu yüzden sizeof() kullanýldýðýnda sonuç ne yazarsan yaz 8 geliyor.
	size = strlen(number);
	printf(" Number of digits: %d\n", size); //for debugging
	for(i=0;i<size;i++){
		temporary[i]=number[i];
	}
	//printf(" Temporary array is created\n"); //for debugging
	for(i=0;i<size;i++){
		number[i]=temporary[(size-1)-i];
	}
	printf(" Mirror array is created: %s\n", number); //for debugging
}
