#include<stdio.h>

int main(void)
{
	int moji;
	
	printf("文字コードを入力してください＝＝>\n");
	scanf("%d", &moji);
	
	printf("入力されたコード「%d」の文字は「%c」です", moji, moji);
	
	return 0;
}