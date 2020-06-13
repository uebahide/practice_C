#include<stdio.h>

int main(void)
{
	int hijosu, josu, syo, amari;
	
	printf("Š„‚ç‚ê‚é”>");
	scanf("%d", &hijosu);
	
	printf("Š„‚é”>");
	scanf("%d", &josu);
	
	syo=hijosu/josu;
	amari=hijosu-(syo*josu);
	
	printf("%d‚ğ%d‚ÅŠ„‚Á‚½—]‚è%d\n", hijosu, josu, amari);
	
	return 0;
}