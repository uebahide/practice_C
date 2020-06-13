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
		printf("�t�@�C�������ɑ��݂��܂�\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen(F_NAME, "w"))==NULL)
	{
		printf("�t�@�C�����J���܂���B\n");
		exit(1);
	}
	
	while(1)
	{
		printf("�w��(0���͏I��)�F");
		scanf("%s", IN.name);
		
		if(IN.name[0]=='0')
		{
			break;
		}
		
		printf("�����F");
		scanf("%f", &IN.dist);
		
		fprintf(fp, "%-13s%3.1f\n", IN.name, IN.dist);
		
		i++;
	}
	
	fclose(fp);
	
	return 0;	
}