#include<stdio.h>

int main(void)
{
	int season;
	
	printf("次の項目の中から数字を選択してください\n");
	printf("\t1,春\n");
	printf("\t2,夏\n");
	printf("\t3,秋\n");
	printf("\t4,冬\n");
	
	printf("選択＝＝＝>");
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
			printf("選択肢にない数字です\n");
			break;
	}
	
	return 0;
}	