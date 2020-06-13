#include<stdio.h>

void kuku(int dann);

int main(void)
{
	int dann, i, j;
	
	while(1)
	{
		while(2)
		{	
			printf("開始する段番号を入力してください＝＝>");
			scanf("%d", &dann);
			
			if(0<=dann&&dann<=9){break;}
		
			printf("0～9までの値を入力してください\n\n");
		}
		
		if(dann==0){break;}
		
		kuku(dann);
	}
	return 0;
}

void kuku(int dann)
{

	int i, j;

	printf("   |     1     2     3     4     5     6     7     8     9\n");
	printf("==========================================================\n");
	
	for(i=dann; i<10; i++)
	{
		printf("%3d|", i);
		
		for(j=1; j<10; j++)
		{
			printf("%6d", i*j);
		}
		
		printf("\n");
	}
}