#include<stdio.h>
int main(void)
{
	int a, b;
	
	printf("割られる数→");
	scanf("%d", &a);
	
	printf("割る数→");
	scanf("%d", &b);
	
	printf("%dを%dで割った余り→%d\n", a, b, a%b);
	
	return 0;
}