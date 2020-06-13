#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME "test4.dat"

int main(void)
{
	char name[128];
	int age, year;
	
	FILE* fp;
	int cnt=0;
	
	if((fp=fopen(F_NAME, "r"))==NULL)
	{
		printf("ファイルがオープンできません。\n");
		fclose(fp);
		exit(1);
	}
	
	printf("名前       年齢   年度\n");
	while(fscanf(fp, "%20s%2d%4d", name, &age, &year)!=EOF)
	{
		printf("%-20s       %2d   %4d\n", name, age, year);
		cnt+=1;
	}
	
	fclose(fp);
	
	printf("読み込み件数=%d件\n", cnt);
	
	return 0;
}