#include<stdio.h>

int main(void)
{
	int *pa;
	int a;
	a=5;
	
	pa=&a;
	
	printf("%p\n", pa);
	printf("%d\n", *pa);
	printf("%d\n", *pa+1);
	printf("%p\n", pa+1);
	printf("%d\n", *(pa+1));
	printf("%d\n", *(pa+2));
	printf("%d\n", *pa+2);
	
	return 0;
}