#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct dictionary
{
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
int main()
{
	int i;
	clrscr();
	printf("\nEnter String:\n");
	scanf("%[^\n]s",str);
	initialize();
	display();
	printf("\n");
	for(i=0;str[i]!='\0';i++)
	{
		C[0]=str[i];
		if(C[0]==' ') continue;
		strcpy(temp,P);
		strcat(temp,C);
		if(findInDictionary(temp)!=-1)
			strcpy(P,temp);
		else
		{
			printf("%4d--->%s",findInDictionary(P),P);
			addToDictionary(temp);
			strcpy(P,C);
		}
	}
	getch();
	return 0;
}

void initialize()
{
	int i;
	start=NULL;
	C[1]='\0';
	C2[1]='\0';
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')continue;
		C2[0]=str[i];
		if(findInDictionary(C2)==-1)
			addToDictionary(C2);
	}
}

int findInDictionary(char c[20])
{
	struct dictionary *ptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
	{
		if(strcmp(ptr->str,c)==0)
			return ptr->index;
	}
	return -1;
}

void addToDictionary(char c[20])
{
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
void display()
{
	struct dictionary *ptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
		printf("%d\t%s\n",ptr->index,ptr->str);
}
