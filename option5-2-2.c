#include<stdio.h>

struct DATA
{
	char name[8+1];
	int age;
	float height;
};

int main(void)
{
	struct DATA data[10];
	struct DATA work;
	
	int i, j, k;
	
	float attl=0, httl=0;
	
	for(i=0; i<10; i++)
	{
		printf("[ %d]�Ԗڂ̖��O(0���͏I��)����>", i+1);
		scanf("%s", data[i].name);
		
		
		if(data[i].name[0]=='0')
		{
			break;
		}
		
		printf("[ %d]�Ԗڂ̔N���>", i+1);
		scanf("%d", &data[i].age);

		attl+=data[i].age;
			
		printf("[ %d]�Ԗڂ̐g������>", i+1);
		scanf("%f", &data[i].height);
		
		httl+=data[i].height;
	}
	
	for(j=0; j<i-1; j++)
	{
		for(k=j+1; k<i; k++)
		{
			if(data[j].age<data[k].age)
			{
				work=data[k];
				data[k]=data[j];
				data[j]=work;
			}
		}
	}
	
	printf("���O       �N��   �g��\n");
	
	for(j=0; j<i; j++)
	{
		printf("%s          %d    %5.1f\n", data[j].name, data[j].age ,data[j].height);
	}
	
	printf("���ϔN�%5.1f  ���ϐg��%5.1f\n", (float)attl/i, httl/i);
	printf("���͌�����%d", i);
	
	return 0;	
}