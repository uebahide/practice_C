#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME "per.dat"

int main(void)
{
	char name[128], age[128], height[128];
	int cnt=1;
	FILE* fp;
	
	if((fp=fopen(F_NAME, "r"))!=NULL)
	{
		printf("�t�@�C�������݂��Ă��܂��B\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen(F_NAME, "w"))==NULL)
	{
		printf("�t�@�C���̓I�[�v���ł��܂���B\n");
		exit(1);
	}
	
	
	while(1)
	{
		printf("[ %d]�Ԗڂ̖��O(0���͏I��)==>", cnt);
		scanf("%s", name);
		
		if(strcmp(name, "0")==0)
		{
			break;
		}
		
		printf("[ %d]�Ԗڂ̔N��==>", cnt);
		scanf("%s", age);
		
		printf("[ %d]�Ԗڂ̐g��==>", cnt);
		scanf("%s", height);
		
		fprintf(fp, "%-20s%2s%5s\n", name, age, height);
		
		cnt++;
	}
	
	fclose(fp);
	
	return 0;
}