#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	int nVowels = 0, nConsonants = 0, nOthers = 0;
	printf("Enter character: ");
	do{
		ch = getchar();
		ch = toupper(ch);
	if(ch>='A'&&ch<='Z'){
		switch(ch){
			case 'A': nVowels ++; break;
			case 'E': nVowels ++; break;
			case 'I': nVowels ++; break;
			case 'O': nVowels ++; break;
			case 'U': nVowels ++; break;
			default:  nConsonants++;
		}
	} else if(ch!=10) nOthers++;	
		
	} while(ch!=10); 
	
	printf("Number of vowels: %d\n", nVowels);
	printf("Number of consonants: %d\n", nConsonants);
	printf("Number of others: %d\n", nOthers);
	
	
	
	
}
