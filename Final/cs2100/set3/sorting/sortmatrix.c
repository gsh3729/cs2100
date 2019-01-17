/* 
ROLL NO:111601006
program name:EX4.c
program description:find element in row wise and coloumn wise sorted matrix.
programmer's name:G.Badrinath Reddy
date:17-9-2017
*/
#include<stdio.h>
#include<stdlib.h>

/* function to check element in matrix */
void searchelement(int a[100][100],int m,int n,int f,int x)
{
    int i,j;
    i=0;
    j=n-1;
    if(f==1)                                 /* Algorithm to check for increasing function */
    {
       while(i<m && j>=0)
       {
           if( a[i][j]==x) 
           {
                  printf("\tElement is present in matrix\n");
                  return;
           }
           if( a[i][j]<x)
           {
                 i=i+1;
           }
           if( a[i][j]>x)
          {
                 j=j-1;
          }
       }
   }

   if(f==0)                                 /* Algorithm to check for decreasing function */
   {
     while(i<m && j>=0) 
     {
       if( a[i][j]==x) 
       {
         printf("\tElement is present in matrix\n");
         return;
       }
       if( a[i][j]<x)
       {
         j=j-1;
       }
       if( a[i][j]>x)
       {
         i=i+1;
       }
     }
   }
   printf("\tElement is not found\n");
   return;
}

int main()
{
     int a[100][100],m,n,i,j,in,de,flag,f,x;        /* Declaration of variables */

     printf("Enter no:of rows(<=100):");            /* prompt the user to enter no:of rows and coloumns */
     scanf(" %d",&m);
     printf("Enter no:of coloumns(<=100):");
     scanf(" %d",&n);

     if(m>100 || n>100)                             /* Give error message when row and coloumns are >100 */
     {
            printf("ERROR! CHECK MATRIX SIZE\n");
            return 0;
     }

      printf("Enter elements of matrix in increasing or decreasing order\n");     /* Prompt the user to enter data either in increasing or decreasing order */
      in=0;
      de=0;
      flag=1;
      for(i=0;i<m;i++)
      {
          for(j=0;j<n;j++)
          {
                 printf("\tEnter [%d,%d] element:",i+1,j+1);
                 scanf(" %d",&a[i][j]);
                 if(i==0 && j==0)
                 {
                     continue;
                 }

                 if(in==1)                                                             /* If it is increasing check if the give elemnt is in increasing order or not */
                 {
                        if(a[i][j-1]>a[i][j] && j!=0)
                        {
                                printf("\tElements are not in sorted order \n");
                                return 0;
                        }
                        if(a[i-1][j]>a[i][j] && i!=0)
                        {
                                printf("\tElements are not in sorted order \n");
                                return 0;
                        }
                  }
 
                 if(de==1)                                                             /* If it is decreasing check if the given element is in decreasing order or not */
                 {
                        if(a[i][j-1]<a[i][j] && j!=0)
                        {
                                printf("\tElements are not in sorted order \n");
                                return 0;
                        }
                        if(a[i-1][j]<a[i][j] && i!=0)
                        {
                                printf("\tElements are not in sorted order \n");
                                return 0;
                        }
                 }

                 if(flag==1)                                                          /* check if it is increasing order or decreasing order */
                 {
                       if(a[i][j-1]<a[i][j] && j!=0) in=1,flag=0;
                       if(a[i-1][j]<a[i][j] && i!=0) in=1,flag=0;
                       if(a[i][j-1]>a[i][j] && j!=0) de=1,flag=0;
                       if(a[i-1][j]>a[i][j] && i!=0) de=1,flag=0;
                 }
          }
     }

     printf("\tMatrix entered is\n");                           
     printf("\t");

     for(i=0;i<m;i++)                                      /* Print the given matrix */
     {
         for(j=0;j<n;j++)
         {
              printf("%d ",a[i][j]);
         }
         printf("\n\t");
     }

    if(de==1)                                              /* if decreasing format[f] is 0 or it is 1 */
    {
       f=0;
    }
    else f=1;

    printf("Enter element to be searched:");               /* Prompt the user to enter element to search for */
    scanf(" %d",&x);

    searchelement(a,m,n,f,x);                              /* Call function to find if element is present or not */

    printf("\n\tComplexity is O(m+n)\n");                 /* print Complexity of search function */
    printf("\tm=number of rows  n=number of coloumns\n");
    return 0;
}


