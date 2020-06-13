#include<stdio.h>

int goukei(int tannka, int suryo);

int main(void)
{
	int tannka, suryo;
	
	while(1)
	{
		printf("***’P‰¿‚É0‚ğ“ü—Í‚·‚é‚Æ“ü—Íˆ—‚ğI—¹‚µ‚Ü‚·***\n");
		
		printf("’P‰¿‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
		scanf("%d", &tannka);
	
		if(tannka==0)
		{
			break;
		}
	
		printf("”—Ê‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
		scanf("%d", &suryo);
	
		printf("’P‰¿ :%6d‰~ ”—Ê :%6dŒÂ\n", tannka, suryo);
		printf("¬Œv :%6d‰~ ‡Œv :%6d‰~\n", tannka*suryo, goukei(tannka, suryo));
	}
	
	return 0;
}

int goukei(tannka, suryo)
{
	int goukei;
	
	goukei=tannka*suryo/100*105;
	
	return goukei;
}