#include<stdio.h>

int main(void)
{
	int x;
	
	printf("���̍��ڂ̒����琔����I�����Ă�������\n1,�t\n2,��\n3,�H\n4,�t\n");
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
			printf("�I�����ɂȂ������ł�\n");
			break;
	
	}
	return 0;
}