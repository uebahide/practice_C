#include<stdio.h>
int main(void)
{
	int a, b;
	
	printf("�����鐔��");
	scanf("%d", &a);
	
	printf("���鐔��");
	scanf("%d", &b);
	
	printf("%d��%d�Ŋ������]�聨%d\n", a, b, a%b);
	
	return 0;
}