#include <stdio.h>
int pal(char *,int );
void main()
{
	char str[20];
	int i=0,len;
	printf("\n Enter the string");
	scanf("%s",str);
	while(str[i]!='\0')
	{
		i++;
	}
	len=i;
	
	pal(str,len);
}
int pal(char *str,int l)
{
	int i=0,j=0;

	if(str[i]==str[l-i-1])
	{
		j++;
	}
	
	if(j==1)
	{
		str[i]!=str[l-i-1];
	}
	else 
	{
		printf("\n NO");
	}
}
