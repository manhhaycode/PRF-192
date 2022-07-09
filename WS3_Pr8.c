#include <stdio.h>
#include <stdlib.h>

 double makeDouble(int ipart, int fraction){
 	double d_f = fraction;
 	
 	while(d_f >= 1){
 		d_f = d_f/10;
	 }
	 if (ipart<0) return ipart - d_f;
 return ipart + d_f;
 }


int main(int argc, char *argv[]) {
	int ipart, fraction;
	printf("Enter integral part: ");
	scanf("%d", &ipart);
	
	do{
	printf("Enter fraction >= 0: ");	
	scanf("%d", &fraction);
    if(fraction<0){
    	printf("You entered fraction < 0, please try again!!!\n");
	}
	} while (fraction<0);
	
	printf("The real number is: %lf", makeDouble(ipart, fraction));
	
	
	
	return 0;
}
