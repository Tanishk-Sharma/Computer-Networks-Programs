#include<stdio.h>
#define INITIAL 1000


int main(){
	int bucket[20], packets[20], i, spackets, n=INITIAL;
	printf("\nEnter number of Packets:\t");
	scanf("%d",&spackets);
	printf("\nEnter Packet Size:");
	packets[0] = 0;
	
	for(i=1; i<=spackets; i++){
		printf("\nPacket %d:\t",i);
		scanf("%d",&packets[i]);
	}
	bucket[0] = 0;
	for(i=1; i<=spackets; i++){
		//printf("\n%d",n);
		if (packets[i]<=n){
			printf("%-3d",i);
			n -= packets[i];
		}
		else if (packets[i]>INITIAL)
			printf("x%-3d",i);
		else
			n = INITIAL;
		n = (n==0)?INITIAL:n;
	}
	return 0;
}
