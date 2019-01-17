#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main ()
{
	char string[1000];
	printf("Enter the string that you want to check wether it is having cycle or not\n");
	scanf("%s",string);

	

	int i , j , k;
	int n = strlen (string);
	
	printf("The cycles are\n");
	for (i =1 ; i <=n/2 ; i++)
	{
		
		for ( j = 0 ; j <= (n - i) ; j++)
		{
			char *temp = (char*)malloc(n * sizeof(char));
			char *copy = (char*)malloc(n * sizeof(char));

			strcpy (copy , string);
			for (k =j ; k < j+i ; k++)
			{
				temp[k-j] = copy[k];
				copy[k] = '0';
			}
			
		
			temp[i] = '\0';
			//printf("%lu\n",strlen(temp));
			
			int flag = 0;
			for (int z = 0 ; z < strlen(temp) ; z++)
			{
						
				if (temp[z] != copy[j+i+z])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				printf("%s\n",temp);

			
			
		}
	}


	return 0;
}