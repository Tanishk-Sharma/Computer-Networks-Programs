#include<stdio.h>

void main(){
	int data[7], rec[7], i, c1, c2, c3, c;
	printf("\nPlease enter a 4-bit message: \n");
	scanf("%d%d%d%d", &data[3], &data[5], &data[6], &data[7]);
	data[1] = data[3] ^ data[5] ^ data[7];
	data[2] = data[3] ^ data[6] ^ data[7];
	data[4] = data[5] ^ data[6] ^ data[7];
	
	printf("\nThe Codeword is:\n")
	for(i=1; i<=7; i++)
		printf("%2d", data[i]);
	
	printf("Please enter received message: \n")
	for(i=1; i<=7; i++)
		printf("%2d", rec[i]);
	c1[1] = rec[1] ^ rec[3] ^ rec[7];
	c1[2] = rec[2] ^ rec[3] ^ rec[7];
	c1[4] = rec[3] ^ rec[5] ^ rec[7];
	c = c3*4 + c2*2 + c1;
	
	if(c==0) 
		printf("\n NO ERROR");
	else{
		printf("\nError found at position %d", c);
		printf("\nThe correct message is: \n");
		if(rec[c] == 0) rec[c] = 1;
		else rec[c] = 0;
		
		for(i=1; i<=7; i++)
			printf("%2d", rec[i]);
	}
}
