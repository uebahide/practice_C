#include<stdio.h>

int cal(int hijosu, int josu);

int main(void)
{
	int hijosu, josu, amari;
	
	printf("�����鐔����>");
	scanf("%d", &hijosu);
	
	printf("���鐔����>");
	scanf("%d", &josu);
	
	amari=cal(hijosu, josu);
	
	printf("%d��%d�Ŋ������]�聁����%d\n", hijosu, josu, amari);
	
	return 0;
}

int cal(int hijosu, int josu)
{
	int syo, amari;
	
	syo=hijosu/josu;
	
	amari=hijosu-syo*josu;
	
	return amari;
}