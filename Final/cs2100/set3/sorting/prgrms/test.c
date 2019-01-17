/**
Author: Sourabh Aggarwal
Roll No.: 111601025
Problem: Ex1
Date: 12/9/2017
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>
#include <limits.h>

typedef long long ll;
typedef unsigned long long llu;
bool first;

#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define read(n) scanf("%d",&n)

int swaps; /**To calculate the minimum number of adjacent swaps required **/

char names[11][1000];
/*int compare(char name1[], char name2[])
{
	int lena = strlen(name1);
	int lenb = strlen(name2);
	if(name1[0]>='A' && name1[0]<= 'Z')
	{
		if(name2[0]>='A' && name2[0]<= 'Z')
		{
			if(name1[0]<=name2[0])*/
void merge(int left, int mid, int right)
{
    int i, j, k;
    const int size1 = mid - left + 1;
    const int size2 =  right - mid;
    /* create temp arrays */
    char Larr[size1][1000], Rarr[size2][1000];
    char temp1[1000],temp2[1000];
    /* Copy data to temp arrays Larr[] and Rarr[] */
    for (i = 0; i < size1; i++)
    	strcpy(Larr[i], names[left+i]);
    for (j = 0; j < size2; j++)
    	strcpy(Rarr[j], names[mid+1+j]);
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    int index;
    while (i < size1 && j < size2)
    {
        index = 0;
    	strcpy(temp1, Larr[i]);
    	strcpy(temp2, Rarr[j]);
    	while(temp1[index]!='\0')
    	{
    		temp1[index] = tolower(temp1[index]);
    		index++;
    	}
    	index = 0;
    	while(temp2[index]!='\0')
    	{
    		temp2[index] = tolower(temp2[index]);
    		index++;
    	}
    	if(Larr[i][0]<='Z'&&Rarr[j][0]<='Z')
        {
            if(Larr[i][0]<Rarr[j][0])
            {
                strcpy(names[k], Larr[i]);
                i++;
            }
            else if(Larr[i][0]==Rarr[j][0])
            {
                if(strcmp(temp1, temp2)<=0)
                {
                    strcpy(names[k], Larr[i]);
                    //arr[k] = Larr[i];
                    i++;
                }
                else///i.e we need to swap
                {
                    strcpy(names[k],Rarr[j]);
                    j++;
                }
            }
            else
            {
                strcpy(names[k],Rarr[j]);
                j++;
            }
        }
        else if(Larr[i][0]<='Z')
        {
            if(Rarr[j][0]<temp1[0])
            {
                strcpy(names[k],Rarr[j]);
                j++;
            }
            else
            {
                strcpy(names[k], Larr[i]);
                i++;
            }
        }
        else if(Rarr[j][0]<='Z')
        {
            if(Larr[i][0]<temp2[0])
            {
                strcpy(names[k],Larr[i]);
                i++;
            }
            else
            {
                strcpy(names[k],Rarr[j]);
                j++;
            }
        }
        else
        {
            if(strcmp(temp1, temp2)<=0)
            {
                strcpy(names[k], Larr[i]);
                //arr[k] = Larr[i];
                i++;
            }
            else///i.e we need to swap
            {
                strcpy(names[k],Rarr[j]);
                j++;
            }
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < size1)
    {
    	strcpy(names[k], Larr[i]);
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < size2)
    {
    	strcpy(names[k],Rarr[j]);
        j++;
        k++;
    }
}

/* Recursively calling merge sort where
   left is for left index and right is right index of the
   sub-array of arr to be sorted */
void mergeSort(int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left+(right-left)/2;
        // Sort first and second halves
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}
int main()
{
	printf("How many names are you going to enter\n");
	int n;
	read(n);
	int i;
	for(i = 0;i<n;i++)
	{
		scanf("%s", names[i]);
	}
	mergeSort(0, n-1);
	printf("Sorted output is given below\n");
	for(i = 0;i<n;i++)
	{
		printf("%s\n", names[i]);
	}
	puts("");
	return 0;
}

