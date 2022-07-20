#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
void swapChar(char *a, char *b){
    char *t = (char *)malloc((strlen(a) + 1)*sizeof(char));
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}
void swapDouble(double *a, double *b){
	double t = *a;
	*a = *b;
	*b = t;
}
char* lTrim (char s[]){
	int i = 0;
	while(s[i]==' ') i++;
	if(i>0) strcpy(&s[0], &s[i]);
	return s;
}

char* rTrim (char s[]){
	int i = strlen(s)-1;
	while(s[i]==' ') i--;
	s[i+1] = '\0';
	return s;
}

char userChoice(){
	char choose;
	printf("\n");
	printf("1- Add a new employee \n2- Find data about employees using a name inputted\n3- Remove an employee based on a code inputted\n4- Print the list in descending order based on salary + allowance\n5- Quit\n");
	printf("Enter selection: ");
	choose = getchar();
	fflush(stdin);
	return choose;
}
void printList(char code[][8], char name[][20], double *salary, double * allowance, int *n){
	for(int i = 0; i<*n; i++){
		printf("Code :%s | Name :%s | Salary :%.4lf | Allowance :%.4lf \n", code[i], name[i], salary[i], allowance[i]);
	}
}
void searchInfo(char code[][8], char name[][20], double *salary, double * allowance, int *n){
	char employee[20];
	int count = 0, pos, search[MAXN];
	printf("Enter name employee: ");
	scanf("%30[^\n]", &employee);
	fflush(stdin);
	strcpy(employee, lTrim(employee));
    strcpy(employee, rTrim(employee));
	strupr(employee);
	for(int i = 0; i<*n; i++){
		if(strcmp(name[i], employee) == 0){
			search[count++] = i;
		}
	}
	if(count==0){
		printf("This employee doesn't exist!!!\n");
	} else {
		for(int i = 0; i<count; i++){
			pos = search[i];
			printf("Code :%s | Name :%s | Salary :%.4lf | Allowance :%.4lf \n", code[pos], name[pos], salary[pos], allowance[pos]);
		}
	}
}

void addEmployee(char code[][8], char name[][20], double *salary, double * allowance, int *n){
	int exists ;

    do{
    	exists = 0;
    	printf("Enter code: ");
		scanf("%30[^\n]", &code[*n]);
		fflush(stdin);
		strcpy(code[*n], lTrim(code[*n]));
		strcpy(code[*n], rTrim(code[*n]));
		strupr(code[*n]);
	    for(int i = 0; i<*n; i++){
			if(strcmp(code[*n], code[i]) == 0){
				exists = 1;
				printf("Code is existed!!!\n");
				break;
			}
		}
		if(exists==0) break;
	} while(1);
	printf("Enter name: ");
	scanf("%30[^\n]", &name[*n]);
	fflush(stdin);
	strcpy(name[*n], lTrim(name[*n]));
    strcpy(name[*n], rTrim(name[*n]));
	strupr(name[*n]);
	printf("Enter salary: ");
	scanf("%lf", &salary[*n]);
	fflush(stdin);		
	printf("Enter allowance: ");
	scanf("%lf", &allowance[*n]);
	fflush(stdin);
	printf("\n");
	(*n)++;		
}

void listDescending (char code[][8], char name[][20], double *salary, double * allowance, int *n){
	int haveswap =0;
	for(int i = 0; i<*n - 1; i++){
		for(int j = *n - 1; j>i; j--){
			if((salary[j] + allowance[j]) > (salary[j-1] + allowance[j-1])){
				swapChar(code[j], code[j-1]);
				swapChar(name[j], name[j-1]);
				swapDouble(&salary[j], &salary[j-1]);
				swapDouble(&allowance[j], &allowance[j-1]);
				haveswap = 1;
			}
		}
	if(haveswap==0){
    	break;
	}
	}
	printList(code, name, salary, allowance, &(*n));
}

void removeEmployee(char code[][8], char name[][20], double *salary, double * allowance, int *n){
	int count = 0, result = 0, pos;
	char remove[8], search[MAXN];
	printf("Enter code: ");
	scanf("%30[^\n]", &remove);
	fflush(stdin);
	strcpy(remove, lTrim(remove));
    strcpy(remove, rTrim(remove));
	strupr(remove);
	for(int i = 0; i<*n; i++){
		if(strcmp(code[i], remove) == 0){
			search[result++] = i;
		}
	}
	if (result == 0){
		printf("This employee doesn't exist!!!");
	}

	for(int i=0; i<result; i++){
		search[i] = search[i] - count;
		for(int j = search[i] + 1; j<*n; j++){
			swapChar(code[j], code[j-1]);
			swapChar(name[j], name[j-1]);
			swapDouble(&salary[j], &salary[j-1]);
			swapDouble(&allowance[j], &allowance[j-1]);
		}
		count++;
		(*n)--;
		strcpy(name[*n], "");
		strcpy(code[*n], "");
		salary[*n] = 0;
		allowance[*n] = 0;
		}	

}

int main(){
	char code[MAXN][8], name[MAXN][20];
	double salary[MAXN], allowance[MAXN];
	char choose;
	int n=0;
	do{
		choose = userChoice();
		switch(choose){
			case '1': addEmployee(code, name, salary, allowance, &n);
					  break;
					  
			case '2': searchInfo(code, name, salary, allowance, &n);
					  break;
					  
			case '3': removeEmployee(code, name, salary, allowance, &n);
					  break;
					  
			case '4': listAscending(code, name, salary, allowance, &n);
					  break;
					  
			default:  choose = '0'; 
					  break;
			
		}
		if(choose< '1' || choose>'4'){
			break;
		}
	} while(1);
}
/*
Test case 

1
H6E2jRE
Nguyen Van A
243423.23134
12.2343
1
VYMHyaH
Nguyen Van C
32993.34231
5345.2341
1
1WtUIoF
Nguyen Van F 
3482.23132
5345.231
1
Bxe71ET
Nguyen Van A
54123.2324
122.4432
1
jeo89k2
Nguyen Van B
248293.238134
3291.23913
1
WIO29rT
Nguyen Van A
329482.82238
13923.392831

*/
