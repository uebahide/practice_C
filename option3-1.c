#include<stdio.h>

int main(void)
{
	int a, b;
	
	printf("数値1→"); scanf("%d", &a);
	printf("数値2→"); scanf("%d", &b);
	
	printf("数値1+数値2=%d\n", a+b);
	printf("数値1-数値2=%d\n", a-b);
	printf("数値1*数値2=%d\n", a*b);
	printf("数値1/数値2=%d\n", a/b);
	
	return 0;
}