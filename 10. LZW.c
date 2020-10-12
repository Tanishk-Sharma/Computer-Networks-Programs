/*
The LZW algorithm is a lossless data compression algorithm created by Terry Welch in 1984. 
This algorithm represents an improved version of the LZ78 algorithm created by Abraham Lempel and Jacob Ziv in 1978.

The idea of the compression algorithm is the following: as the input data is being processed, a dictionary keeps a correspondence between the longest encountered words and a list of code values. 
The words are replaced by their corresponding codes and so the input file is compressed. Therefore, the efficiency of the algorithm increases as the number of long, repetitive words in the input data increases.

Either when using the compression or the decompression methods, the elements of the input array must be of type unsigned char, which is also the type of the resulting array's elements.

The following example generates a sample array of N random letters (from A to Z) and compresses it. 
The compressed array is then decompressed to see if the sample array is identical to the uncompressed array. 
The size of the compressed array is also displayed, to prove the efficiency of the LZW algorithm.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct dictionary{
	int index;
	char str[20];
	struct dictionary *next;
};

struct dictionary *start;
char P[20],C[2],C2[2],str[20],temp[20];
void initialize();
int findInDictionary(char [20]);
void addToDictionary(char [20]);
void display();
int ind=0;
int main(){
	int i;
	clrscr();
	printf("\nEnter String:\n");
	scanf("%[^\n]s",str);
	initialize();
	display();
	printf("\n");
	for(i=0;str[i]!='\0';i++){
		C[0]=str[i];
		if(C[0]==' ') continue;
		strcpy(temp,P);
		strcat(temp,C);
		if(findInDictionary(temp)!=-1)
			strcpy(P,temp);
		else{
			printf("%4d--->%s",findInDictionary(P),P);
			addToDictionary(temp);
			strcpy(P,C);
		}
	}
	getch();
	return 0;
}

void initialize(){
	int i;
	start=NULL;
	C[1]='\0';
	C2[1]='\0';
	for(i=0;str[i]!='\0';i++){
		if(str[i]==' ')continue;
		C2[0]=str[i];
		if(findInDictionary(C2)==-1)
			addToDictionary(C2);
	}
}

int findInDictionary(char c[20]){
	struct dictionary *ptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->next){
		if(strcmp(ptr->str,c)==0)
			return ptr->index;
	}
	return -1;
}

void addToDictionary(char c[20]){
	struct dictionary *ptr,*new_node;
	new_node=(struct dictionary *)malloc(sizeof(struct dictionary));
	for(ptr=start;ptr->next!=NULL;ptr=ptr->next);
	if(start==NULL)
		start=new_node;
	strcpy(new_node->str,c);
	new_node->index=++ind;
	new_node->next=NULL;
	ptr->next=new_node;
}

void display(){
	struct dictionary *ptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
		printf("%d\t%s\n",ptr->index,ptr->str);
}
