#include<stdio.h>

struct DATA
{
	char name[5];
	int height;
	int weight;
	int age; 
};

int main(void)
{
	int i, j;
	struct DATA work;
	
	struct DATA data[5]=
	{
		{"�O�Y",160,55,22},
		{"�͍�",153,52,27},
		{"�{��",157,50,24},
		{"����",168,55,30},
		{"����",176,72,32}
	};
	
	for(i=0; i<4; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(data[i].age<data[j].age)
			{
				printf("a");
				work=data[i];
				data[i]=data[j];
				data[j]=work;
				printf("b\n");
			}
		}
	}
	
	printf("���O\t�g��\t�̏d\t�N��\n");
	
	for(i=0; i<5; i++)
	{
		printf("%s \t%d \t%d \t%d\n", data[i].name, data[i].height, data[i].weight, data[i].age);
	}
	
	return 0;
}