#include<stdio.h>
#include<stdlib.h>

#define F_NAME "score.dat"

int main(void)
{
	int s[10];                             /* 得点別の人数を格納する配列      */
	
	/* ファイルのデータを読み込むための変数群 */
	char class;
	int num;
	char name[10+1];
	int escore, mscore, lscore;                            /* 得点を格納するための変数  */
	
	/* その他の変数群*/
	char f[100];                           /* 終了フラグ                      */
	int i, j;                              /* ループカウンタ                  */
	FILE* fp;                              /* ファイル構造体のポインタ        */
	
	/* 移行が前処理*/
	
	/* 初期化ループ*/
	for(i=0; i<11; i++)
	{
		s[i]=0;
	}
	
	if((fp=fopen(F_NAME, "r"))==NULL)
	{
		printf("ファイルが開けません。\n");
	}

	fscanf(fp, "%c%2d%s%3d%3d%3d%*c", &class, &num, name, &escore, &mscore, &lscore);

	printf("点数区分  人数\n");
	
	/* 集計処理 */
	while(strcmp(f, "EOF")!=0)
	{
		if(0<=escore&&escore<=9)
		{
			s[0]+=1;
		}
		
		else if(10<=escore&&escore<=19)
		{
			s[1]+=1;
		}
		
		else if(20<=escore&&escore<=29)
		{
			s[2]+=1;
		}
		
		else if(30<=escore&&escore<=39)
		{
			s[3]+=1;
		}
		
		else if(40<=escore&&escore<=49)
		{
			s[4]+=1;
		}
		
		else if(50<=escore&&escore<=59)
		{
			s[5]+=1;
		}
		
		else if(60<=escore&&escore<=69)
		{
			s[6]+=1;
		}
		
		else if(70<=escore&&escore<=79)
		{
			s[7]+=1;
		}
		
		else if(80<=escore&&escore<=89)
		{
			s[8]+=1;
		}
		
		else if(90<=escore&&escore<=99)
		{
			s[9]+=1;
		}
		
		else
		{
			s[10]+=1;
		}
		
		if(fscanf(fp, "%c%2d%s%3d%3d%3d%*c", &class, &num, name, &escore, &mscore, &lscore)==EOF)
		{
			strcpy(f, "EOF");
		}
	}
	
	fclose(fp);
	
	for(i=0; i<10; i++)
	{
		printf("%2d - %2d  :", i*10, i*10+9);
		
		for(j=0; j<s[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	printf("100      :");
	for(j=0; j<s[10]; j++)
	{
		printf("*");
	}
	printf("\n");

	return 0;
}