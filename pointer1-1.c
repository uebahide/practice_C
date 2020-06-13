#include<stdio.h>

int main(void)
{
	
	printf("a\n");
	char* message="Hello.";
	printf("b\n");

	
	printf("%\n", message);
	
	printf("c\n");
	message[5]='!';
	printf("d\n");
	
	printf("%s\n", message);
	
	return 0;
}