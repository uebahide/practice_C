#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char name[128],age[128],year[128];
	int cnt=0;
	FILE* fp;
	
	if((fp=fopen("test4.dat", "r"))!=NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B\n");
		fclose(fp);
		exit(1);
	}
	
	if((fp=fopen("test4.dat", "w"))==NULL)
	{
		printf("�t�@�C�����I�[�v���ł��܂���B\n");
		exit(1);
	}
	
	while(1)
	{
		printf("���O������");
		scanf("%s", name);
		
		if(strcmp(name, "0")==0)
		{
			break;
		}
		
		printf("�N�����");
		scanf("%s", age);
		
		printf("�N�x������");
		scanf("%s", year);
		
		fprintf(fp, "%-20s%2s%4s\n", name, age, year);
		cnt++;
	}
	
	fclose(fp);
	
	printf("�����o������=%d\n", cnt);
	
	return 0;
}