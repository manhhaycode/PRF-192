#include<stdio.h>
#include<math.h>
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
    printf("Max and min of %d is: %d, %d\n",start, max, min);
}

void Pr2() {
	int n;
	do {
		printf("Enter number >= 0: ");
		scanf("%d",&n);
		if(n<0) {
			printf("You entered number < 0, please try again!!!\n");
		}		
	} while (n<0);

	printMinMaxDigits(n);

}
