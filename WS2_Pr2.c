#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		long long income, tf, ti, it, pa = 9000000, pd = 3600000;
	int n;
	printf("Your income of this year: ");
	scanf("%lld", &income);
	printf("Number of dependent: ");
	scanf("%d", &n);
	tf = 12*(pa + n*pd);
	ti = income - tf; 
	if(ti<=0){
		ti = 0;
	}
	printf("Tax-free income: %lld\n", tf);
	printf("Taxable income: %lld\n", ti);	
	
	if(ti<=5000000){
		it = (5*ti)/100;
	} else{
		if (ti<=10000000){
			it = (10*(ti - 5000000))/100 +(5000000*5)/100;
		} else {
			if (ti <= 18000000){
				it = (15*(ti-10000000))/100 + (5000000*5)/100 + (5000000*10)/100;
			} else it = (20*(ti-18000000))/100 + (5000000*5)/100 + (5000000*10)/100 + (8000000*15)/100;
		}
	}
	
	printf("Income tax: %lld\n", it);
    return 0;
}
