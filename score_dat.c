#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME "score.dat"

typedef struct 
{
	char class;
	int number;
	char name[10+1];
	int engscore;
	int matscore;
	int lanscore;
}record;

int main(void)
{
	record IN;
	FILE* fp;
	int i=0;
	
	if((fp=fopen(F_NAME, "r"))!=NULL)
	{
		printf("ファイルが既に存在します\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen(F_NAME, "w"))==NULL)
	{
		printf("ファイルが開けません。\n");
		exit(1);
	}
	
	while(1)
	{
		printf("クラス(0入力終了)：");
		scanf("%c", &IN.class);
		
		if(IN.class=='0')
		{
			break;
		}
		
		printf("学生番号：");
		scanf("%d", &IN.number);
		
		printf("名前：");
		scanf("%s", IN.name);
		
		printf("英語：");
		scanf("%d", &IN.engscore);
		
		printf("数学：");
		scanf("%d", &IN.matscore);
		
		printf("国語：");
		scanf("%d", &IN.lanscore);
		
		printf("a\n");
		fprintf(fp, "%c%2d%-10s%3d%3d%3d\n", IN.class, IN.number, IN.name, IN.engscore, IN.matscore, IN.lanscore);
		printf("b\n");
		
		i++;
	}
	
	fclose(fp);
	
	return 0;	
}