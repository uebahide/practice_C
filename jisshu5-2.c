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
		{"三浦",160,55,22},
		{"河合",153,52,27},
		{"本木",157,50,24},
		{"柳沢",168,55,30},
		{"中野",176,72,32}
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
	
	printf("名前\t身長\t体重\t年齢\n");
	
	for(i=0; i<5; i++)
	{
		printf("%s \t%d \t%d \t%d\n", data[i].name, data[i].height, data[i].weight, data[i].age);
	}
	
	return 0;
}