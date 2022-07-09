#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char userChoice(){
	char choose;
	printf("\n");
	printf("1- Add a student \n2- Remove a student\n3- Search a student\n4- Print the list in ascending order\n5- Quit\n");
	printf("Enter selection: ");
	choose = getchar();
	fflush(stdin);
	return choose;
}

void swap(char *a, char *b){
    char *t = (char *)malloc((strlen(a) + 1)*sizeof(char));
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
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
void addAStudents(char names[][31], int *n){
     printf("Enter name students: ");
     scanf("%30[^\n]", names[*n]);
     fflush(stdin);
     strcpy(names[*n], lTrim(names[*n]));
     strcpy(names[*n], rTrim(names[*n]));
     strupr(names[*n]);
     (*n)++;
}

void listAscending(char names[][31],char sort[][31], int *n){
	for(int i = 0; i<*n; i++){
		strcpy(sort[i], names[i]);
	}
	for(int i = 0; i<*n - 1; i++){
		for(int j = *n - 1; j>i; j--){
			if(strcmp(sort[j], sort[j-1])<0){
				swap(sort[j], sort[j-1]);
			}
		}
	}
}
int searchAStudents(char names[][31], int *search, int *n){
	char name[31];
	int count = 0;
	printf("Enter name students: ");
	scanf("%30[^\n]", &name);
	fflush(stdin);
	strcpy(name, lTrim(name));
    strcpy(name, rTrim(name));
	strupr(name);
	for(int i = 0; i<*n; i++){
		if(strcmp(names[i], name) == 0){
			search[count++] = i;
		}
	}
	return count;
}
void printList(char names[][31] , int *n){
	for(int i = 0; i<*n; i++){
		printf("a[%d]: ", i);
		puts(names[i]);
	}
}

void removeAStudents(char names[][31], int *search, int result, int *n){
	int count = 0;
	for(int i=0; i<result; i++){
		search[i] = search[i] - count;
		for(int j = search[i] + 1; j<*n; j++){
			swap(names[j],names[j-1]);
		}
		count++;
		(*n)--;
		strcpy(names[*n], "");
		}	

}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n = 0, result, search[100], countS;
	char nameStudents[100][31], sort[100][31], remove[31], choose;
	do{
		choose  = userChoice();
		switch(choose){
			case '1': addAStudents(nameStudents, &n);
					break;
					
			case '2':	result = searchAStudents(nameStudents,search, &n);
					if(result == 0){
						printf("Student does not exist!!!\n\n");
					} else{
						removeAStudents(nameStudents, search, result, &n);	
					}
					
					break;
			
			case '3': countS = searchAStudents(nameStudents,search, &n);
				    if(countS==0){
						printf("Student does not exist!!!\n\n");
					} else{
						printf("Student %s is at a position: ", nameStudents[search[0]]);
						for(int i = 0; i<countS; i++){
							printf(" %d", search[i]);
						}
						printf("\n\n");
					}	
			        break;
			
			case '4': listAscending(nameStudents, sort, &n);
					printList(sort, &n);
					break;
					
			case '5': break;
			
			default: choose = 5;
				   	 break;
		}
		if(choose< '1' || choose>'4'){
			break;
		}
	} while(1);
	return 0;
}

/*
test case
1
   Nguyen Van O   
1
   Nguyen Van J   
1
   Nguyen Van H   
1
   Nguyen Van M    
1
   Nguyen Van P    
1
   Nguyen Van L    
1
   Nguyen Van N   
1
  Nguyen Van C
1
Nguyen Van Q
1
Nguyen Van A
1
Nguyen Van K
1
Nguyen Van G
1
Nguyen Van B
1
Nguyen Van F
1
Nguyen Van E
1
Nguyen Van c
1
Nguyen Van D
1
Nguyen Van I
1
nguyen van c
1
nguyen van b
1
nguyen van p
1
nguyen van tra my
*/
