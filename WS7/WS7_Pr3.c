#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
char userChoice(){
	char choose;
	printf("\n");
	printf("1- Adding a new soft drink \n2- Printing out items which belong to a known make.\n3- Printing out items whose volumes are between v1 and v2\n4- Printing the list in ascending order based on volumes then prices\n5- Quit\n");
	printf("Enter selection: ");
	choose = getchar();
	fflush(stdin);
	return choose;
}
void swapChar(char *a, char *b){
    char *t = (char *)malloc((strlen(a) + 1)*sizeof(char));
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}
void swapInt(int *a, int *b){
	int t = *a;
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

void addDrink(char name[][20], char make[][20], int *volume, int *price, int *duration , int *n){
	int exists ; 
	do{
		exists = 0;
		printf("Enter name: ");
		scanf("%30[^\n]", &name[*n]);
		fflush(stdin);
		strcpy(name[*n], lTrim(name[*n]));
		strcpy(name[*n], rTrim(name[*n]));
		strupr(name[*n]);
		printf("Enter make: ");
		scanf("%30[^\n]", &make[*n]);
		fflush(stdin);
		strcpy(make[*n], lTrim(make[*n]));
		strcpy(make[*n], rTrim(make[*n]));
		strupr(make[*n]);
		printf("Enter volume: ");
		scanf("%d", &volume[*n]);
		fflush(stdin);
		printf("Enter price: ");
		scanf("%d", &price[*n]);
		fflush(stdin);
		printf("Enter duration: ");
		scanf("%d", &duration[*n]);
		fflush(stdin);
		for(int i = 0; i<*n; i++){
			if(strcmp(name[*n], name[i])==0 && strcmp(make[*n], make[i])==0 && volume[*n]==volume[i] && price[*n]==price[i] && duration[*n]==duration[i]){
				exists = 1;
				printf("Drink is existed!!!\n");
				break;
			}
		}
		if(exists==0) {
			(*n)++;
			break;
		}
	} while (1);	
	
}

void searchMake(char name[][20], char make[][20], int *volume, int *price, int *duration , int *n){
	char makeSearch[20];
	int count = 0, pos, search[MAXN];
	printf("Enter make: ");
	scanf("%30[^\n]", &makeSearch);
	fflush(stdin);
	strcpy(makeSearch, lTrim(makeSearch));
    strcpy(makeSearch, rTrim(makeSearch));
	strupr(makeSearch);
	for(int i = 0; i<*n; i++){
		if(strcmp(make[i], makeSearch) == 0){
			search[count++] = i;
		}
	}
	if(count==0){
		printf("There are no drinks made from this material!!!\n");
	} else {
		for(int i = 0; i<count; i++){
			pos = search[i];
			printf("Name : %s | Make : %s | Volume : %d | Price : %d | Duration: %d\n", name[pos], make[pos], volume[pos], price[pos], duration[pos]);
		}
	}
}
void searchVolume(char name[][20], char make[][20], int *volume, int *price, int *duration , int *n){
	int v1, v2;
	int count = 0, pos, search[MAXN];
	printf("Enter volume 1: ");
	scanf("%d", &v1);
	fflush(stdin);
	printf("Enter volume 2: ");
	scanf("%d", &v2);
	if(v1>v2){
		int t;
		t = v2;
		v2 = v1;
		v1 = t;
	}
	fflush(stdin);
	for(int i = 0; i<*n; i++){
		if(volume[i]>=v1 && volume[i]<=v2){
			search[count++] = i;
		}
	}
	if(count==0){
		printf("Drink doesn't exist!!!!!!\n");
	} else {
		for(int i = 0; i<count; i++){
			pos = search[i];
			printf("Name : %s | Make : %s | Volume : %d | Price : %d | Duration: %d\n", name[pos], make[pos], volume[pos], price[pos], duration[pos]);
		}
	}
}
void listAscending(char name[][20], char make[][20], int *volume, int *price, int *duration , int *n){
	int haveswap =0;
	for(int i = 0; i<*n - 1; i++){
		for(int j = *n - 1; j>i; j--){
			if(volume[j]>volume[j-1] || (volume[j]==volume[j-1] && price[j] > price[j-1])){
				swapChar(name[j], name[j-1]);
				swapChar(make[j], make[j-1]);
				swapInt(&volume[j], &volume[j-1]);
				swapInt(&price[j], &price[j-1]);
				haveswap = 1;
			}
		}
	if(haveswap==0){
    	break;
	}
	}
	
	for(int i = 0; i<*n; i++){
		printf("Name : %s | Make : %s | Volume : %d | Price : %d | Duration: %d\n", name[i], make[i], volume[i], price[i], duration[i]);
	}
}
int main(){
	char choose, name[MAXN][20], make[MAXN][20];
	int volume[MAXN], price[MAXN], duration[MAXN], n=0;
		do{
		choose = userChoice();
		switch(choose){
			case '1': addDrink(name, make, volume, price, duration, &n);
					  break;
					  
			case '2': searchMake(name, make, volume, price, duration, &n);
					  break;
					  
			case '3': searchVolume(name, make, volume, price, duration, &n);
					  break;
					  
			case '4': listAscending(name, make, volume, price, duration, &n);
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
C2
tea 
330
10000
12
1
cafe phin
cafe
500
15000
12
1
cafe espresso
cafe
550
20000
12
1
7up
lemon
330
10000
10
1
mirinda orange
orange
330
10000
11
1
twister
orange
330
12000
9
*/
