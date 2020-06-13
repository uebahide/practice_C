#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME "per3.dat"

int main(void)
{
	char name[128], age[128], height[128];
	int cnt=1;
	FILE* fp;
	
	if((fp=fopen(F_NAME, "r"))!=NULL)
	{
		printf("ファイルが存在しています。\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen(F_NAME, "wb"))==NULL)
	{
		printf("ファイルはオープンできません。\n");
		exit(1);
	}
	
	
	while(1)
	{
		printf("[ %d]番目の名前(0入力終了)==>", cnt);
		scanf("%s", name);
		
		if(strcmp(name, "0")==0)
		{
			break;
		}
		
		printf("[ %d]番目の年齢==>", cnt);
		scanf("%s", age);
		
		printf("[ %d]番目の身長==>", cnt);
		scanf("%s", height);
		
		fwrite(name, strlen(name), 1, fp);
		fwrite(age, strlen(age), 1, fp);
		fwrite(height, strlen(height), 1, fp);
		
		cnt++;
	}
	
	fclose(fp);
	
	return 0;
}