#include<stdio.h>

int Goukei(int tannka, int syoukei);

int main(void)
{
	int tannka, suuryou, syoukei, goukei;
	
	while(1)
	{
		printf("’P‰¿‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
		scanf("%d", &tannka);
		
		if(tannka==0)
		{
			break;
		}
		
		printf("”—Ê‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
		scanf("%d", &suuryou);
		
		syoukei=tannka*suuryou;
		
		goukei=Goukei(tannka, suuryou);
		
		printf("’P‰¿  :%d‰~ ”—Ê  :%dŒÂ\n", tannka, suuryou);
		printf("¬Œv  :%d‰~ ‡Œv  :%d‰~\n", syoukei, goukei);
	}
	
	return 0;
}

int Goukei(int tannka, int suuryou)
{
	int goukei;
	
	goukei=tannka*suuryou/100*105;
	
	return goukei;
}
