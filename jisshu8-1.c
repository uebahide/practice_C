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
		printf("�t�@�C�������ɑ��݂��܂��B\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen(F_NAME, "w"))==NULL)
	{
		printf("�t�@�C�����I�[�v���ł��܂���B\n");
		fclose(fp);
		exit(1);
	}
	
	
	
	for(i=0; ;i++)
	{
		printf("���O==>");
		scanf("%s", val[i].name);
		
		if(val[i].name[0]=='0')
		{
			break;
		}
		
		printf("�N��==>");
		scanf("%d", val[i].age);
		
		printf("�N�x==>");
		scanf("%d", val[i].nenndo);
	}
	
	printf("�t�@�C���֏o�͂��܂����H(y/n) ");
	scanf("%s", buf);
	if(strcmp(buf, "y")==0||strcmp(buf, "Y")==0)
	{
		for(j=0; j<i; j++)
		{
			fprintf(fp, "%-20s%2d%4d\n", val[j].name, val[j].age, val[j].nenndo);
		}
	}
	
	fclose(fp);
	
	printf("�����o������=%d��\n", j);
	
	return 0;
}