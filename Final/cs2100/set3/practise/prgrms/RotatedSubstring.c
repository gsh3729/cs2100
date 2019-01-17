//This program is suppose to check wether a substring is rotated or not
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int isSubstring (char string[] , char sub[]);

int main ()
{
	char string[1000];
	char substring[1000];

	printf("Enter the string\n");
	scanf("%s",string);

	printf("Enter the substring \n");
	scanf("%s",substring);

	//char c[2000];
	strcat (string , string);
	if (isSubstring(string , substring)== 1 )
		printf("The given string is rotated\n");

	else
		printf("No it is not the rotated version of the given substring\n");

	return 0;

}

int isSubstring (char string[] , char sub[])
//this function checks wether sub is subString of string or not
{
	int count1 = strlen(string);
	int count2 = strlen(sub);
	int flag = 1;





	for (int i =0 ; i<= count1 - count2 ; i++)
	{
		for (int j = i ; j < i+count2 ; j++)
		{
			flag = 1;
			if (string[j] != sub[j-i])
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			break;
	}

	return flag;
} 