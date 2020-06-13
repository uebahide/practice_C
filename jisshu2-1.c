#include<stdio.h>

int main(void)
{
	int code;
	
	printf("文字コードを入力してください→");
	scanf("%d", &code);
	
	printf("入力された文字コード「%d」の文字は「%c」です\n",code, code);
	
	return 0;

}