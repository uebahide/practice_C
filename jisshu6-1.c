#include<stdio.h>

int amari(int josu, int hijosu);

int main(void)
{
	int josu, hijosu;
	
	printf("�����鐔������>");
	scanf("%d", &hijosu);
	
	printf("���鐔������>");
	scanf("%d", &josu);
	
	amari(josu, hijosu);
	
	printf("%d��%d�Ŋ������]�聁����%d\n", hijosu, josu, amari(josu, hijosu));
	
	return 0;
}

int amari(int josu, int hijosu)
{
	int syo, amari;
	
	syo=hijosu/josu;
	amari=hijosu-(syo*josu);
	
	return amari; 
}