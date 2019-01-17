/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to implement merge sort with help recursive function call to sort of array of integer in ascending order. 
	DATE=12/09/17   				*/
#include <stdio.h>
#include <string.h>

int isSubstring(char s2[20],char s1[20]);

void main()
{
	char s1[20],s2[20];
	int i;
	
	printf("\n Enter the first string ");
	scanf("%s",s1);
	printf("\n Enter the second string ");
	scanf("%s",s2);
	
	//strcat(s2,s2);
	i=isSubstring(s2,s1);
	if(i==1)
	{
		printf("\ns2 is a rotation of s1\n");
	}
	else
	{
		printf("\ns2 is not a rotation of s1 \n");
	}
}
int isSubstring(char s1[20],char s2[20])
{
	int i,j,k,l=0,x,a;
	for(i=0;s1[i]!='\0';i++)
	{	
		
		for(j=0;s2[j]!='\0';j++)
		{
			l=0;
			k=i;
			if(s1[k]==s2[j])
			{
				k++;
				l++;
			}
			else
			{
				break;
			}
		}
		if(l==strlen(s1))
		{
			a=1;
			break;
		}
	}
	printf(" a%ld",strlen(s1));
	if(a==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
			
			
	
	

