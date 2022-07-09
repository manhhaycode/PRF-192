#include <stdio.h>
#include <stdlib.h>
void characterData(){
	char c1, c2;
	int d;
    printf("Enter characters: ");
	scanf("%c%c", &c1, &c2);
	fflush(stdin);
	printf("%d %d\n", c1, c2);
	if(c1>c2){
		int t = c1;
		c1 = c2;
		c2 = t;
	}
	d= c2-c1;
	printf("Range: %d\n\n", d);
	for(int e = c2; e>=c1; e--){
		printf("%c : %d, %Xh\n", e, e, e);
	}
}

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


int main(){
	int choose, d, m, y;
	do{
		printf("Enter choose: ");
		scanf("%d",&choose);
		fflush(stdin);
		switch(choose){
			case 1: characterData();
					break;
				
			case 2: printf("Enter day: ");
					scanf("%d", &d);
					fflush(stdin);
					printf("Enter month: ");
					scanf("%d", &m);
					fflush(stdin);
					printf("Enter year: ");
					scanf("%d", &y);
					fflush(stdin);
					if (vaildDate(d, m, y)){
						printf("Vaild date!!!\n");
					} else 	printf("Invaild date!!!\n");
					break;
					
			default: break;
		}
	}while(choose!=3);
}
