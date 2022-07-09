#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int intRandom(int min, int max){
	return min + rand()%max;
}

int main(int argc, char *argv[]) {
	srand((int)(time(0)));
	int total, count, x, y;
	do{
	    printf("Enter number: ");
	    scanf("%d", &total);
	} while(total <= 2 || total >= 20);
	count = 1;
	
	do{
		x = intRandom(1,10);
		do{
			y = intRandom(1,10);
		} while(x==y);
		printf("Result of picks %d and %d: %d + %d\n", count++,count, x, y);
		
		if((x+y) == total){
			printf("You got your total in %d picks!", count);
		}
		
		count++;
		
	} while (x+y != total);
	
	
	
	return 0;
}
