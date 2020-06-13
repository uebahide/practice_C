#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char name[128],age[128],year[128];
	int cnt=0;
	FILE* fp;
	
	if((fp=fopen("test4.dat", "r"))!=NULL)
	{
		printf("ファイルが既に存在します。\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen("test4.dat", "w"))==NULL)
	{
		printf("ファイルがオープンできません。\n");
		exit(1);
	}
	
	while(1)
	{
		printf("名前＝＝＞");
		scanf("%s", name);
		
		if(strcmp(name, "0")==0)
		{
			break;
		}
		
		printf("年齢＝＝＞");
		scanf("%s", age);
		
		printf("年度＝＝＞");
		scanf("%s", year);
		
		fprintf(fp, "%-20s%2s%4s\n", name, age, year);
		cnt++;
	}
	
	fclose(fp);
	
	printf("書き出し件数=%d\n", cnt);
	
	return 0;
}