#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* area;
	
	area=(int*)malloc(sizeof(int));
	
	if(area==NULL)
	{
		printf("�������m�ێ��s\n");
	}
	else
	{
		*area=100;
		printf("�l�F%d �A�h���X�F%p\n", *area, area);
		free(area);
	}
	
	return 0;
}