#include<stdio.h>

int Goukei(int tannka, int syoukei);

int main(void)
{
	int tannka, suuryou, syoukei, goukei;
	
	while(1)
	{
		printf("単価を入力してください＝＝>");
		scanf("%d", &tannka);
		
		if(tannka==0)
		{
			break;
		}
		
		printf("数量を入力してください＝＝>");
		scanf("%d", &suuryou);
		
		syoukei=tannka*suuryou;
		
		goukei=Goukei(tannka, suuryou);
		
		printf("単価  :%d円 数量  :%d個\n", tannka, suuryou);
		printf("小計  :%d円 合計  :%d円\n", syoukei, goukei);
	}
	
	return 0;
}

int Goukei(int tannka, int suuryou)
{
	int goukei;
	
	goukei=tannka*suuryou/100*105;
	
	return goukei;
}
