#include<stdio.h>

int main(void)
{
	int  i, j;
	
	printf("�J�n����i�ԍ�����͂��Ă�������==>");
	scanf("%d", &i);
	
	while(0>=i||i>=10)
	{	
		printf("0�`9�܂ł̒l����͂��Ă�������\n");
		printf("�J�n����i�ԍ�����͂��Ă�������==>");
		scanf("%d", &i);
	}
	
	printf("   |     1     2     3     4     5     6     7     8     9\n");
	printf("==========================================================\n");
	
	for(; i<10; i++)
	{
		printf(" %d |", i);
		
		for(j=1; j<10; j++)
		{
			printf("%6d", i*j);
		}
		
		printf("\n");
	}
	
	return 0;
	
}