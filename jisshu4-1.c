#include<stdio.h>

int main(void)
{
	int seireki;
	
	printf("�����4���œ��͂��Ă���������");
	scanf("%d", &seireki);
	
	if(seireki%4!=0)
	{
		printf("����%d�͂��邤�N�ł͂���܂���\n", seireki);
	}
	
	else if(seireki%4==0&&seireki%100!=0)
	{
		printf("����%d�͂��邤�N�ł�\n", seireki);
	}
	
	else if(seireki%100==0&&seireki%400==0)
	{
		printf("����%d�͂��邤�N�ł�\n", seireki);
	}
	
	else
	{
		printf("����%d�͂��邤�N�ł͂���܂���\n", seireki);
	}
	
	return 0;
}
	