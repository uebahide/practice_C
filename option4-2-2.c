#include<stdio.h>

int main(void)
{
	int MAX, i, j;
	
	while(1)
	{
		printf("�J�n����i�ԍ�����͂��Ă�������������>");
		scanf("%d", &MAX);
	
		if(0<=MAX||MAX<=9)
		{
			break;
		}
		
		printf("0�`9�܂ł̒l����͂��Ă�������\n");
	}
	
	printf("   |    1    2    3    4    5    6    7    8    9\n");
	printf("=================================================\n");
	
	for(i=MAX; i<10; i++)
	{
		printf("  %d|", i);
		
		for(j=1; j<10; j++)
		{
			printf("%5d", i*j);
		}
		
		printf("\n");
	}
} 