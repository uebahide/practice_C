#include<stdio.h>

int main(void)
{
	int seireki;
	
	printf("西暦を4桁で入力してください→");
	scanf("%d", &seireki);
	
	if(seireki%4!=0)
	{
		printf("西暦%dはうるう年ではありません\n", seireki);
	}
	
	else if(seireki%4==0&&seireki%100!=0)
	{
		printf("西暦%dはうるう年です\n", seireki);
	}
	
	else if(seireki%100==0&&seireki%400==0)
	{
		printf("西暦%dはうるう年です\n", seireki);
	}
	
	else
	{
		printf("西暦%dはうるう年ではありません\n", seireki);
	}
	
	return 0;
}
	