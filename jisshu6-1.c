#include<stdio.h>

int amari(int josu, int hijosu);

int main(void)
{
	int josu, hijosu;
	
	printf("Š„‚ç‚ê‚é”>");
	scanf("%d", &hijosu);
	
	printf("Š„‚é”>");
	scanf("%d", &josu);
	
	amari(josu, hijosu);
	
	printf("%d‚ğ%d‚ÅŠ„‚Á‚½—]‚è%d\n", hijosu, josu, amari(josu, hijosu));
	
	return 0;
}

int amari(int josu, int hijosu)
{
	int syo, amari;
	
	syo=hijosu/josu;
	amari=hijosu-(syo*josu);
	
	return amari; 
}