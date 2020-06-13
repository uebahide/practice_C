#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	int i;
	int* area;

	area=(int *)malloc(sizeof(int)*(argc-1));
	
	for(i=0; i<(argc-1); i++)
	{
		*(area+i)=atoi(*(argv+i+1));
	}
	
	for(i=0; i<(argc-1); i++)
	{
		printf("*(area+%d)=%d\n", i, *(area+i));
	}
	
	free(area);
	
	return 0;
}