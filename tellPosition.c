#include<stdio.h>
#include<string.h>

char* tellPosition(char* str, char c);
 
int main(void)
{
	char str[100];
	char c;
	char *p;
	
	printf("検索対象文字列＝＞");
	gets(str);                                                      /* 検索対象文字列を入力 */
	
	printf("検索する文字＝＞");
	scanf("%c", &c);                                                /* 検索する文字をにゅうりょく*/
	
	p=tellPosition(str, c);                                         /* 検索処理 */
	
	/* 結果文字列を出力 */
	if(p!=NULL)
	{
		printf("一致文字以降＝＞%s\n", p);
	}
	
	else
	{
		printf("一致文字以降＝＞検索する文字と一致しません\n");
	}
	
	return 0;
} 

char* tellPosition(char* str, char c)
{
	int i;                                                           /* ループカウンタ */
	int length;                                                      /* 文字列のサイズ */
	char* p=NULL;                                                   
	
	length=strlen(str);
	
	/* 検索処理 */
	for(i=0; i<length; i++)
	{
		if(*(str+i)==c)
		{
			p=str+i;
			break;
		}
	}
	
	return p;
}