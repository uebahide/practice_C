#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME "dist.dat"

typedef struct 
{
	char name[12+1];
	float dist;
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
		printf("駅名(0入力終了)：");
		scanf("%s", IN.name);
		
		if(IN.name[0]=='0')
		{
			break;
		}
		
		printf("距離：");
		scanf("%f", &IN.dist);
		
		fprintf(fp, "%-13s%3.1f\n", IN.name, IN.dist);
		
		i++;
	}
	
	fclose(fp);
	
	return 0;	
}