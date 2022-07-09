#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int intRandom(int min, int max){
	return min + rand()%6 - 1;
}

int main(int argc, char *argv[]) {
	srand((int)(time(0)));
	int total, count, x, y;
	do{
	    printf("Enter number: ");
	    scanf("%d", &total);
	} while(total<2 || total >12);
	count = 1;
	
	do{
		x = intRandom(2,6);
		y = intRandom(2,6);
		printf("Result of throw %d : %d + %d\n", count, x, y);
		
		if((x+y) == total){
			printf("You got your total in %d throws!", count);
		}
		
		count++;
		
	} while (x+y != total);
	
	
	
	return 0;
}
