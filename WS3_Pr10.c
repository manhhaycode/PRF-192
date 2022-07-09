#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printMinMaxDigits(int n){
	int start = n;
	int digit, max, min;
	digit = n%10;
	n = n/10;
	max = min = digit;
	while(n>0){
		digit = n%10;
		n = n/10;
		if (min>digit) min = digit ;
		if (max<digit) max = digit;
	}
    printf("Max and min of %d is: %d, %d",start, max, min);
}



int main(int argc, char *argv[]) {
	int n;
	do {
		printf("Enter number >= 0: ");
		scanf("%d",&n);
		if(n<0) {
			printf("You entered number < 0, please try again!!!\n");
		}		
	} while (n<0);

	printMinMaxDigits(n);
	
	
	
	return 0;
}
