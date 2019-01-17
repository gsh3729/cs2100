/*
size_t strlen(const char *str)		//string length
size_t strnlen(const char *str, size_t maxlen)		//string length only if the string length is less than the max length otherwise returns max value

int strcmp(const char *str1, const char *str2)		//string comparison
													//If string1 < string2 OR string1 is a substring of string2 then it would result in a negative value. If string1 > string2 then it would return positive value.
													If string1 == string2 then you would get 0(zero) when you use this function for compare strings.

int strncmp(const char *str1, const char *str2, size_t n)		//compares two string only upto n characters
char *strcat(char *str1, char *str2)							//concatenates two string and return the concatenated string
char *strncat(char *str1, char *str2, int n)					//concatenates two string only upto n characters and return that string
char *strcpy( char *str1, char *str2)							//copies string two into string one
char *strncpy( char *str1, char *str2, size_t n)				//Copies str2 to str 1
																//If str2 > n ; it copies only the first n characters else copies the whole string
char *strchr(char *str, int ch)									//search for charcater ch in string str
char *strrchr(chr *str , int ch)								//search for the last occurence character  ch in string str
char *strstr(char *str, char *srch_term)						//searches for the substring in a given string
strlwr															//converts the string into lower cases
strupr															//converts the string into upper cases
stricmp															//compares two string without considering the cases
strincmp														//compares two string without considering the cases only upto n character
tolower															//Note that this is for the characters only
toupper
strdup

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main ()
{
	char a[100];
	char b[100];

	printf("Enter the strings\n");
	scanf("%s %s",a,b);

	//strlen
	printf("The length of the string is %lu and %lu\n",strlen(a) ,strlen(b));

	//strnlen
	printf("Length using max length is %lu and %lu \n",strnlen(a , 5) , strnlen(b , 5) );

	//strcmp
	if (strcmp (a , b) == 0)
		printf("True\n");

	else if (strcmp (a , b) < 0)
		printf("1 is smaller than 2\n");

	else if (strcmp (a , b) > 0)
		printf ("1 is greater than 2\n");


	//strncmp 
	if (strncmp (a , b , 4) < 0)
		printf("%s\n",a);

	//strcat
	printf("The concatenated string is %s\n",strcat(a , b));			//Note that b is concatenated to a

	//strncat
	printf("The concatenated string is %s\n",strncat (a , b , 2));		//Note that 2 is not the total length of the string

	//strcpy
	char c[100];
	strcpy (c , a);
	printf("The string c is %s    \n",c);

	//strncpy
	char d[100];
	strncpy (d , a , 4);
	printf("The string is using limieted copying %s   \n",d);


	//strchr
	printf("The %s\n",strchr(a , 'r'));

	//strrchr
	printf("The %s\n",strrchr(a , 'r'));



	//strstr
	printf("The substring is %s\n",strstr(a , "sri"));
	if (strstr(a , "srish") != NULL)
		printf("Yes i found you\n");

	
	//strdup
	char e[100];
	char f[100];
	char g[100] , *h;
	printf("Enter the string is \n");
	scanf("%s %s",e,f);
	strcpy(g , e);
	h = strdup (f);
	printf("%s %s \n",e , g);
	printf("%s %s \n",f , h);
	e[0] = 'o';
	f[0] = '0';

	printf("%s %s \n",e , g);
	printf("%s %s \n",f , h);


	return 0;



	
}