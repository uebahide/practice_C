#include<stdio.h>

struct DATA
{
	char name[100];
	int height;
	int weight;
	int age;
};

void sort(struct DATA *p);

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
	
	int i;
	struct DATA *p;
	
	p=data;
	
	printf("%p\n", p);
	
	sort(data);
	
	printf("名前   身長   体重   年齢\n");
	
	for(i=0; i<5; i++)
	{
		printf("%s   %d    %d     %d\n", data[i].name, data[i].height, data[i].weight, data[i].age);
	}
	
	return 0;
}

void sort(struct DATA *p)
{
	int i, j;
	struct DATA work;
	
	for(i=0; i<4; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if((p+i)->age > (p+j)->age)
			{
				work=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=work;
			}
		}
	}
}