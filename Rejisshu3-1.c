#include<stdio.h>

int main(void)
{
	int hijosu, josu, syo, amari;
	
	printf("�����鐔����>");
	scanf("%d", &hijosu);
	
	printf("���鐔����>");
	scanf("%d", &josu);
	
	syo=hijosu/josu;
	amari=hijosu-(syo*josu);
	
	printf("%d��%d�Ŋ������]�聁����%d\n", hijosu, josu, amari);
	
	return 0;
}