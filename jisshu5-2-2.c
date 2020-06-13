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
		{"中野", 176, 72, 32},
		{"河合", 153, 52, 27},
		{"三浦", 160, 55, 22},
		{"柳沢", 168, 55, 30},
		{"本木", 157, 50, 24}
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
	
	printf("名前   身長   体重   年齢\n");
	
	for(i=0; i<5; i++)
	{
		 printf("%s   %d   %d   %d\n", data[i].name, data[i].height, data[i].weight, data[i].age);
	}
	
	return 0;
}