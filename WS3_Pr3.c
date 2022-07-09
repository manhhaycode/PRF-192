#include <stdio.h>
#include <stdlib.h>

int getRelPos (double x, double y, double r){

	double d2 = x*x + y*y;       /* d^2 = x^2 + y^2 */
	
	if (d2 < r*r){
	
		return 0;    /* the point is in the circle */
	} else {
		if (d2 == r*r){
			return 1;      /* the point is on the circle */
		} else return -1;  /* the point is out of the circle */
	}
	
	
}

int main(int argc, char *argv[]) {
	
	
    double x, y, r;
	
	do{
		printf("Enter radius: ");
		scanf("%lf", &r);
		if (r<0){
		printf("You have entered radius < 0, plese enter radius again!!!\n");
		}
	} while (r<0);
	printf("Enter coordinates of x: ");
	scanf("%lf", &x);
	printf("Enter coordinates of y: ");
	scanf("%lf", &y);
	int result = getRelPos(x, y, r);
	if(result == 0){
    	printf("The point is in the circle!!!");
	} else {
		if (result == 1){
			printf("The point is on the circle!!!");
			
		} else {
			printf("The point is out of the circle !!!");
		}
		
	}
	
	return 0;
	
	
	
}




