#include <stdio.h>
#include <stdlib.h>

int isISBN(int *ISBN){
	int C[9], T = ISBN[9];
	for(int i = 0, j = 10; i<9; i++, j--){
		C[i] = j*ISBN[i];
		T+=C[i];
	}
	return T%11;
}

void intToArray(int *ISBN, long long n){
	for (int i = 9; i >=0 ; i--){
		if(n != 0){
			ISBN[i] = n%10;
			n = n/10;
		
		}else {
			ISBN[i] = 0;
		}		
	}
}

int main(){
	int ISBN[10];
	long long n;
	do{
		printf("=== ISBN Validator ===\n");
		printf("Enter ISBN (0 to quit): ");
	    scanf("%lld", &n);
	    fflush(stdin);
	    intToArray(ISBN, n);
		if(n>0 && n<= 1000000000){
            if(isISBN(ISBN)==0){
				printf("This is a valid ISBN. \n");
			} else {
				printf("This is not a valid ISBN. \n");
			}
		}

	} while(n!=0);

	printf("Have a Nice Day!\n");
	return 0;
}
