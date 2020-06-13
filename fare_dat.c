#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME "fare.dat"

typedef struct 
{
	int dist;
	int fare;
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
		printf("距離(0入力終了)：");
		scanf("%d", &IN.dist);
		
		if(IN.dist==0)
		{
			break;
		}
		
		printf("運賃：");
		scanf("%d", &IN.fare);
		
		fprintf(fp, "%2d%4d\n", IN.dist, IN.fare);
		
		i++;
	}
	
	fclose(fp);
	
	return 0;	
}