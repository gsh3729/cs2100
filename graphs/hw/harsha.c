#include <stdio.h>
void incre(int *p);
void main()
{
	int *p,d;
	p=&d;
	*p=0;
	printf("\np init%d",*p);
	incre(p);
	printf("\np incr%d",*p);
}
void incre(int *p)
{
	//printf("\np loop%d",*p);
	(*p)=(*p)+1;
}
