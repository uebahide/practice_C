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
		printf("�N���X(0���͏I��)�F");
		scanf("%c", &IN.class);
		
		if(IN.class=='0')
		{
			break;
		}
		
		printf("�w���ԍ��F");
		scanf("%d", &IN.number);
		
		printf("���O�F");
		scanf("%s", IN.name);
		
		printf("�p��F");
		scanf("%d", &IN.engscore);
		
		printf("���w�F");
		scanf("%d", &IN.matscore);
		
		printf("����F");
		scanf("%d", &IN.lanscore);
		
		printf("a\n");
		fprintf(fp, "%c%2d%-10s%3d%3d%3d\n", IN.class, IN.number, IN.name, IN.engscore, IN.matscore, IN.lanscore);
		printf("b\n");
		
		i++;
	}
	
	fclose(fp);
	
	return 0;	
}