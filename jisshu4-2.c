#include<stdio.h>

int main(void)
{
	int x;
	
	printf("Ÿ‚Ì€–Ú‚Ì’†‚©‚ç”š‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢\n1,t\n2,‰Ä\n3,H\n4,t\n");
	scanf("%d", &x);
	
	switch(x)
	{
		case(1):

			printf("SPRING\n");
			break;
		
		case(2):
			printf("SUMMER\n");
			break;
		
		case(3):
			printf("AUTUMN\n");
			break;
		
		case(4):
			printf("WINTER\n");
			break;
		
		default:
			printf("‘I‘ğˆ‚É‚È‚¢”š‚Å‚·\n");
			break;
	
	}
	return 0;
}