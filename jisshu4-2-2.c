#include<stdio.h>

int main(void)
{
	int season;
	
	printf("���̍��ڂ̒����琔����I�����Ă�������\n");
	printf("\t1,�t\n");
	printf("\t2,��\n");
	printf("\t3,�H\n");
	printf("\t4,�~\n");
	
	printf("�I��������>");
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
			printf("�I�����ɂȂ������ł�\n");
			break;
	}
	
	return 0;
}	