#include<stdio.h>

int goukei(int tannka, int suryo);

int main(void)
{
	int tannka, suryo;
	
	while(1)
	{
		printf("***�P����0����͂���Ɠ��͏������I�����܂�***\n");
		
		printf("�P������͂��Ă�����������>");
		scanf("%d", &tannka);
	
		if(tannka==0)
		{
			break;
		}
	
		printf("���ʂ���͂��Ă�����������>");
		scanf("%d", &suryo);
	
		printf("�P�� :%6d�~ ���� :%6d��\n", tannka, suryo);
		printf("���v :%6d�~ ���v :%6d�~\n", tannka*suryo, goukei(tannka, suryo));
	}
	
	return 0;
}

int goukei(tannka, suryo)
{
	int goukei;
	
	goukei=tannka*suryo/100*105;
	
	return goukei;
}