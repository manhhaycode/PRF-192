#include <stdio.h>
#include <stdlib.h>


int vaildDate(int d, int m, int y){
	int maxd =31; /*max day of months 1, 3, 5, 7, 8, 10, 12 */
	if(d<1 || d>31 || m<1 || m>12) return 0;
	if (m == 4 || m==6 || m==9 || m == 11){         /* months 4, 6, 9, 10 have 30 days */
		maxd = 30;
	} else{
		if(m == 2){
			/* leap year  */
			if ( y%400 == 0 ||  y%4 == 0 && y%100 != 0 ){
				maxd = 29;
			} else {
				maxd = 28;
			}
		}
	}
	
	return d <= maxd;
}

void Pr2() {
    
	int d, m, y;
	printf("Enter day: ");
	scanf("%d", &d);
	printf("Enter month: ");
	scanf("%d", &m);
	printf("Enter year: ");
	scanf("%d", &y);
	if (vaildDate(d, m, y)){
		printf("Vaild date!!!\n");
	} else 	printf("Invaild date!!!\n");
}
