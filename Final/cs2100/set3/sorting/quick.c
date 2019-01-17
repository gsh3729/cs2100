/*
	PROGRAMMER'S NAME : G SRIHARSHA
	ROLLNO:111601005
	PROGRAM DESCRIPTION : program to implement quick sort with help recursive function call to sort of array of integer in ascending order. 
	DATE=12/09/17   				*/
#include <stdio.h>

void quicksort(int a[],int l,int h);
int partition(int a[],int l, int h);
void swap(int *a,int *b);

void main()
{
	int a[100],len,i;
	printf("\n Enter the length of the list (<100) ");
	scanf("%d",&len);
	for(i=0;i<len;i++)//taking input from user
	{
		printf("\n Enter the %d element in the list ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n Before sorting the array is \n");
	for(i=0;i<len;i++)//printing the output sorted array
	{
		printf(" %d",a[i]);		
	}
	quicksort(a,0,len-1);
	printf("\n The sorted array is \n");
	for(i=0;i<len;i++)//printing the output sorted array
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}
void quicksort(int a[],int l,int h)
{
	int pi;
	if(l<h) // if l<h is not true then the recursion will stop 
	{
		pi=partition(a,l,h); // calling the partition function
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,h);
	}
}
int partition(int a[],int l, int h)//In partition function we choose the last element as pivot and arrange the array such that elements that are smaller than pivot are left side to pivot and elements that are larger than pivot are right side to pivot 
{
	int pivot,i,pi;
	pi=l;
	pivot=a[h];
	for(i=l;i<h;i++)
	{
		if(a[i]<=pivot)
		{
			swap(&a[i],&a[pi]);
			pi=pi+1;
		}
	}
	swap(&a[pi],&a[h]);
	return pi;
}
void swap(int *a,int *b)//function to swap two numbers
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
	

// int pivot=a[start],p1=start+1,i,temp; //start element

// for(i=start+1;i<=end;i++)
// {

// if(a[i]<pivot)
//     {
//         if(i!=p1)
//       {  
//             temp=a[p1];
//             a[p1]=a[i];
//             a[i]=temp;
//       }    p1++;
//     }
// }

//         a[start]=a[p1-1];
//         a[p1-1]=pivot;

// return p1-1;
// }




//   void quicksort(int *a,int start,int end)
// {
//  int p1;
//  if(start<end)
// {
//     p1=partition(a,start,end);
//     quicksort(a,start,p1-1);
//     quicksort(a,p1+1,end);
// }
// }



// #include <iostream>  //middle element
// #include <iomanip>

// using namespace std;

// #define SIZE 9

// /* swap a[i] and a[j] */
// void swap(int a[], int i, int j)
// {	
// 	int temp;
// 	temp = a[i];
// 	a[i] = a[j];
// 	a[j] = temp;
// }

// void print(const int arr[])
// {
// 	for(int i=0;i < SIZE; i++) {
// 		cout << setw(3) << arr[i];
// 	}
// 	cout << endl;
// }

// /* sort arr[left]...arr[right] into increasing order */
// void qsort(int a[], int left_index, int right_index)
// {
// 	int left, right, pivot;
// 	if(left_index >= right_index) return;

// 	left = left_index;
// 	right = right_index;

//         // pivot selection
// 	pivot = a[(left_index + right_index) /2];

//         // partition
// 	while(left <= right) {
// 		while(a[left] < pivot) left++;
// 		while(a[right] > pivot) right--;
// 		if(left <= right) {
// 			swap(a,left,right);
// 			left++; right--;
// 		}
// 		print(a);		
// 	}
    
//         // recursion
// 	qsort(a,left_index,right);
// 	qsort(a,left,right_index);
// }

// int main()
// {
// 	int a[SIZE]={1, 12, 5, 26, 7, 14, 3, 7, 2};
// 	print(a);
// 	qsort(a,0,SIZE-1);
// }





	




















