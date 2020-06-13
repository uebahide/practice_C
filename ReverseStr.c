#include<stdio.h>
#include<string.h>

void reverseStr(char *str);

int main(void)
{
	char str[100];                             /* 対象文字列の領域*/
	
	printf("入力文字列＝＞");                
	scanf("%s", str);                          /* 文字列標準入力  */
	
	reverseStr(str);                           /* 並べ替え処理    */
	
	printf("入れ替え後＝＞%s\n", str);
	
	return 0;
}

void reverseStr(char *str)
{
	int i;                                     /* ループカウンタ  */
	int length;                                /* 文字列のサイズ  */
	char work;                                 /* 退避用変数      */
	
	length=strlen(str);                        /* 文字列のサイズを代入 */
	
	for(i=0; i<length/2; i++)                  /* 入れ替え処理    */
	{
		work=*(str+i);
		*(str+i)=*(str+(length-i-1));
		*(str+(length-i-1))=work;
	}
}