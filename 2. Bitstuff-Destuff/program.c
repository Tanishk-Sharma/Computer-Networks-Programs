#include<stdio.h>
#define MAXSIZE 100

int main(){
	char *p, *q;
	char temp;
	char original;
	char stuff[MAXSIZE];
	char destuff[MAXSIZE];
	
	int count=0;
	
	printf("\nPlease enter Bit information: \n");
	scanf("%s", original);
	p = original;
	q = stuff;
	
	while(*p!='\o'){
		if(*p=='0'){
			*q = *p;
			q++;
			p++;
		}
		else{
			while(*p=='1' && count!=5){
				count++;
				*q = *p;
				q++;
				p++;
			}
			if(count==5){
				*q = '0';
				q++;
			}
			count=0;
		}
	}
	*q = '\o';
	printf("\nBit Stuffed:\n");
	printf("%s", stuff);
	
	// Destuff:
	
	p = stuff;
	q = destuff;
	
	while(*p!='\o'){
		if(*p=='0'){
			*q = *p;
			q++;
			p++;
		}
		else{
			while(*p=='1' && count!=5){
				count++;
				*q = *p;
				q++;
				p++;
			}
			if(count==5)
				p++;
			count=0;
		}
	}
	*q = '\o';
	printf("\De-Stuffed:\n");
	printf("%s", destuff);
	getch();
}
