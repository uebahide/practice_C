#include<stdio.h>

int goukei(int tannka, int suryo);

int main(void)
{
	int tannka, suryo;
	
	while(1)
	{
		printf("***単価に0を入力すると入力処理を終了します***\n");
		
		printf("単価を入力してください＝＝>");
		scanf("%d", &tannka);
	
		if(tannka==0)
		{
			break;
		}
	
		printf("数量を入力してください＝＝>");
		scanf("%d", &suryo);
	
		printf("単価 :%6d円 数量 :%6d個\n", tannka, suryo);
		printf("小計 :%6d円 合計 :%6d円\n", tannka*suryo, goukei(tannka, suryo));
	}
	
	return 0;
}

int goukei(tannka, suryo)
{
	int goukei;
	
	goukei=tannka*suryo/100*105;
	
	return goukei;
}