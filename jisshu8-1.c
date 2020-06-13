#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME "syain.dat"

struct PRODUCT
{
	char name[20+1];
	int age;
	int nenndo; 
};

int main(void)
{
	FILE* fp;
	char buf[100];
	int i, j;
	
	struct PRODUCT val[100];
	
	if((fp=fopen(F_NAME, "r"))!=NULL)
	{
		printf("ファイルが既に存在します。\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen(F_NAME, "w"))==NULL)
	{
		printf("ファイルがオープンできません。\n");
		fclose(fp);
		exit(1);
	}
	
	
	
	for(i=0; ;i++)
	{
		printf("名前==>");
		scanf("%s", val[i].name);
		
		if(val[i].name[0]=='0')
		{
			break;
		}
		
		printf("年齢==>");
		scanf("%d", val[i].age);
		
		printf("年度==>");
		scanf("%d", val[i].nenndo);
	}
	
	printf("ファイルへ出力しますか？(y/n) ");
	scanf("%s", buf);
	if(strcmp(buf, "y")==0||strcmp(buf, "Y")==0)
	{
		for(j=0; j<i; j++)
		{
			fprintf(fp, "%-20s%2d%4d\n", val[j].name, val[j].age, val[j].nenndo);
		}
	}
	
	fclose(fp);
	
	printf("書き出し件数=%d件\n", j);
	
	return 0;
}