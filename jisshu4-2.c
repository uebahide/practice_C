#include<stdio.h>

int main(void)
{
	int x;
	
	printf("次の項目の中から数字を選択してください\n1,春\n2,夏\n3,秋\n4,春\n");
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
			printf("選択肢にない数字です\n");
			break;
	
	}
	return 0;
}