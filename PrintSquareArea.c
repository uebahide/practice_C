#include<stdio.h>

void drawSquare(int h, int w);
void printSquareArea(int **pp, int size);

int main(void)
{
	int a[3]={8, 6, 0};
	int b[3]={9, 13, 0};
	int c[3]={5, 3, 0};
	int *p[3];
	int size;
	
	p[0]=a;
	p[1]=b;
	p[2]=c;
		
	size=sizeof(p)/sizeof(p[0]);

	printSquareArea(p, size);
	
	return 0;
}

void printSquareArea(int **pp, int size)
{
	int i;
	
	for(i=0; i<size; i++)
	{
		*(*(pp+i)+2) = *(*(pp+i)) * *(*(pp+i)+1);
		printf("�ʐρF%d\n", *(*(pp+i)+2));
		drawSquare(*(*(pp+i)+0), *(*(pp+i)+1));
		printf("\n");
	}
}

void drawSquare(int h, int w)
{
	int i, j;
	
	for(i=0; i<h; i++)
	{
		for(j=0; j<w; j++)
		{
			printf("*");
		}
		
		printf("\n");
	}
}