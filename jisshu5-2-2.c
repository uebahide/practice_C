#include<stdio.h>

struct DATA
{
	char name[8+1];
	int height;
	int weight;
	int age;
};

int main(void)
{
	struct DATA data[5]=
	{
		{"����", 176, 72, 32},
		{"�͍�", 153, 52, 27},
		{"�O�Y", 160, 55, 22},
		{"����", 168, 55, 30},
		{"�{��", 157, 50, 24}
	};
	
	struct DATA work;
	
	int i, j;
	
	for(i=0; i<4; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(data[i].age>data[j].age)
			{
				work=data[i];
				data[i]=data[j];
				data[j]=work;
			}
		}
	}
	
	printf("���O   �g��   �̏d   �N��\n");
	
	for(i=0; i<5; i++)
	{
		 printf("%s   %d   %d   %d\n", data[i].name, data[i].height, data[i].weight, data[i].age);
	}
	
	return 0;
}