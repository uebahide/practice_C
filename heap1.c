#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* area;
	
	area=(int*)malloc(sizeof(int));
	
	if(area==NULL)
	{
		printf("メモリ確保失敗\n");
	}
	else
	{
		*area=100;
		printf("値：%d アドレス：%p\n", *area, area);
		free(area);
	}
	
	return 0;
}