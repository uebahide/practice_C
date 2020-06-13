#include<stdio.h>

int main(void)
{
	int i;
	
	for(i=1; i<11; i++)
	{
		printf("x=%5d x*x=%5d x*x*x=%5d x*x*x*x=%5d\n", i, i*i, i*i*i, i*i*i*i);
	}
	
	return 0;
}