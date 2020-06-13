#include<stdio.h>

int main(void)
{
	int season;
	
	printf("Ÿ‚Ì€–Ú‚Ì’†‚©‚ç”š‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢\n");
	printf("\t1,t\n");
	printf("\t2,‰Ä\n");
	printf("\t3,H\n");
	printf("\t4,“~\n");
	
	printf("‘I‘ğ>");
	scanf("%d", &season);
	
	switch(season)
	{
		case 1:
			printf("SPRING\n");
			break;
			
		case 2:
			printf("SUMMER\n");
			break;
		
		case 3:
			printf("AUTUMN\n");
			break;
		
		case 4:
			printf("WINTER\n");
			break;
			
		default:
			printf("‘I‘ğˆ‚É‚È‚¢”š‚Å‚·\n");
			break;
	}
	
	return 0;
}	