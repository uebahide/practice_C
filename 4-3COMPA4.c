#include<stdio.h>
#include<stdlib.h>

#define F_NAME "saiten.dat"

int main(void)
{
	int num;
	char name[10+1];
	int eng, math, lan;
	int total, average;
	int in;
	FILE* fp;

	while(1)
	{
			if((fp=fopen(F_NAME, "r"))==NULL)
		{
			printf("ファイルが開けません。\n");
			exit(1);
		}
		
		printf("出席番号==");
		if(scanf("%d", &in)==EOF)
		{
			break;
		}
		
		while(fscanf(fp, "%2d%s%3d%3d%3d%*c", &num, name, &eng, &math, &lan)!=EOF)
		{	
			if(num==in)
			{
				total=eng+math+lan;
				average=total/3;
				
				printf("%2d %-10s %3d %3d %3d %3d %3d\n", num, name, eng, math, lan, total, average);
				
				break;
			}
		}
		
		if(num!=in)
		{
			printf("該当する出席番号はありません。\n");
		}
		
		fclose(fp);
	}
	
	return 0;
}