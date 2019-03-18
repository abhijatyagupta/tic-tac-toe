#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	int a[10], i, j, k, b, z=1;
	char n, p1[100], p2[100], p1name[100], p2name[100];
	printf("\n\n\t");
	while(z<=29){
		printf("* ");
		if(z == 13){
			for(; z < 16; z++){
				if(z == 14){
					printf("*\tTIC-TAC-TOE\t*");
				}
				else{
					printf("\n\t*\t\t\t*\n\t");
				}
			}
		}
		z++;
	}
	printf("\n\n\t ENTER PLAYER ");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("1");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf(" NAME: ");
	scanf(" %[^\n]%*c", p1name);
	printf("\n\n");
	printf("\t ENTER PLAYER ");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf("2");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf(" NAME: ");
	scanf(" %[^\n]%*c", p2name);
	system("cls");
	printf("\n1\t2\t3\n\n4\t5\t6\n\n7\t8\t9\n\n");
	for(j = 0; j < 9; j++){
		if(j%2 == 0){
			n = 'X';
		}
		else{
			n = 'O';
		}
		if(n == 'X'){
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			printf("%s", p1name);
		}
		else{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			printf("%s", p2name);
		}
		SetConsoleTextAttribute(hConsole, saved_attributes);
		printf(": Press the number which you want to replace \"");
		if(n == 'X'){
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		}
		else{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		}
		printf("%c", n); 
		SetConsoleTextAttribute(hConsole, saved_attributes);
		printf("\" with\n");
		scanf("%d", &b);
		if(a[b] == 'X' || a[b] == 'O' || b <= 0 || b > 9){
		printf("Invalid move!\n\n");
		j--;
		}
		else{
			system("cls");
			printf("\n");
			for(i = 1, k = 1; i <= 9; i++, k++){
				if(k != b){
					if(a[i] != 'X' && a[i] != 'O'){
						a[i]=k;
						printf("%d\t", a[i]);
						if(i%3==0){
							printf("\n\n");
						}
					}
					else if(a[i] == 'X'){
						SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
						printf("%c\t", a[i]);
						SetConsoleTextAttribute(hConsole, saved_attributes);
						if(i%3==0){
							printf("\n\n");
						}
					}
					else{
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
						printf("%c\t", a[i]);
						SetConsoleTextAttribute(hConsole, saved_attributes);
						if(i%3==0){
							printf("\n\n");
						}
					}
				}
				else{
					a[b] = n;
					if(n == 'X'){
						SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					}
					else{
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					}
					printf("%c\t", a[b]);
					SetConsoleTextAttribute(hConsole, saved_attributes);
					if(i%3==0){
						printf("\n\n");
					}
				}
			}
			if((j >= 5) && (a[1]==a[2] && a[2]==a[3]) || (a[4]==a[5] && a[5]==a[6]) || (a[7]==a[8] && a[8]==a[9]) || (a[1]==a[4] && a[4]==a[7]) || (a[2]==a[5] && a[5]==a[8]) || (a[3]==a[6] && a[6]==a[9]) || (a[1]==a[5] && a[5]==a[9]) || (a[3]==a[5] && a[5]==a[7])){
				if(a[b]=='X'){
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					printf("%s", p1name);
					SetConsoleTextAttribute(hConsole, saved_attributes);
					printf(" WINS!\n");
					break;
				}
				else{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					printf("%s", p2name);
					SetConsoleTextAttribute(hConsole, saved_attributes);
					printf(" WINS!\n");
					break;
				}
			}
		}	
	}
	if(j == 9){
		printf("MATCH DRAW!\n");
	}
}