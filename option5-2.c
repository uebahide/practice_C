#include<stdio.h>

struct DATA
{
	char name[20];
	int age;
	float height; 
};

int main(void)
{
	int i=0, j, k;
	int attl=0; 
	float httl=0.0;
	struct DATA work;
	struct DATA data[11];
	
	for(i=0; i<10; i++)
	{
		printf("[ %d]�Ԗڂ̖��O�i0���͏I���j==>", i+1);
		scanf("%s", data[i].name);
		
		if(data[i].name[0]=='0')
		{
			break;	
		}
		
		printf("[ %d]�Ԗڂ̔N��==>", i+1);
		scanf("%d", &data[i].age);
		
		printf("[ %d]�Ԗڂ̐g��==>", i+1);
		scanf("%f", &data[i].height);
	}
	
	for(j=0; j<i; j++)
	{
		printf("%s  %d  %.2f\n", data[j].name, data[j].age, data[j].height);	
	}
	
	for(j=0; j<i; j++)
	{
		attl+=data[j].age;
		httl+=data[j].height;
	}
	printf("%d\n", i);
	
	for(j=0; j<i-1; j++)
	{
		for(k=j+1; k<i; k++)
		{
			printf("%d\n", k);
			if(data[j].age<data[k].age)
			{
				printf("a");
				work=data[j];
				data[j]=data[k];
				data[k]=work;
				printf("b");
			}
			printf("c\n");
		}
	}
	
	printf("aaa\n");
	
	printf("���O      �N��  �g��\n");
	
	for(j=0; j<i; j++)
	{
		printf("%-20s          %3d  %5.1f\n", data[j].name, data[j].age, data[j].height);
	}
	
	printf("bbb\n");
	
	printf("\n");
	
	printf("���ϐg����%4.1f ���ϑ̏d��%5.1f\n", (float)attl/i, httl/i);
	printf("���͌�����%d\n", i);
	
	return 0;
}