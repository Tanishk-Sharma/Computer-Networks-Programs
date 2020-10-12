/*
The Leaky Bucket Algorithm is an algorithm used in packet switched computer networks and telecommunications networks. 
It can be used to check that data transmissions, in the form of packets, conform to defined limits on bandwidth and burstiness (a measure of the unevenness or variations in the traffic flow). 
It can also be used as a scheduling algorithm to determine the timing of transmissions that will comply with the limits set for the bandwidth and burstiness(network scheduler). 
*/

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
