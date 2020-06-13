#include<stdio.h>

int cal(int hijosu, int josu);

int main(void)
{
	int hijosu, josu, amari;
	
	printf("Š„‚ç‚ê‚é”>");
	scanf("%d", &hijosu);
	
	printf("Š„‚é”>");
	scanf("%d", &josu);
	
	amari=cal(hijosu, josu);
	
	printf("%d‚ğ%d‚ÅŠ„‚Á‚½—]‚è%d\n", hijosu, josu, amari);
	
	return 0;
}

int cal(int hijosu, int josu)
{
	int syo, amari;
	
	syo=hijosu/josu;
	
	amari=hijosu-syo*josu;
	
	return amari;
}