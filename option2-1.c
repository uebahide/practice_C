#include<stdio.h>

int main(void)
{
	char moji;
	
		printf("英大文字を入力してください→");
		scanf("%c", &moji);
		
		printf("英小文字は「%c」です\n", moji+32);
		
		return 0;
}