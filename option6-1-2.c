#include<stdio.h>

int Goukei(int tannka, int syoukei);

int main(void)
{
	int tannka, suuryou, syoukei, goukei;
	
	while(1)
	{
		printf("�P������͂��Ă�����������>");
		scanf("%d", &tannka);
		
		if(tannka==0)
		{
			break;
		}
		
		printf("���ʂ���͂��Ă�����������>");
		scanf("%d", &suuryou);
		
		syoukei=tannka*suuryou;
		
		goukei=Goukei(tannka, suuryou);
		
		printf("�P��  :%d�~ ����  :%d��\n", tannka, suuryou);
		printf("���v  :%d�~ ���v  :%d�~\n", syoukei, goukei);
	}
	
	return 0;
}

int Goukei(int tannka, int suuryou)
{
	int goukei;
	
	goukei=tannka*suuryou/100*105;
	
	return goukei;
}
