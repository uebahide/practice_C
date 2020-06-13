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
		printf("[ %d]番目の名前（0入力終了）==>", i+1);
		scanf("%s", data[i].name);
		
		if(data[i].name[0]=='0')
		{
			break;	
		}
		
		printf("[ %d]番目の年齢==>", i+1);
		scanf("%d", &data[i].age);
		
		printf("[ %d]番目の身長==>", i+1);
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
	
	printf("名前      年齢  身長\n");
	
	for(j=0; j<i; j++)
	{
		printf("%-20s          %3d  %5.1f\n", data[j].name, data[j].age, data[j].height);
	}
	
	printf("bbb\n");
	
	printf("\n");
	
	printf("平均身長＝%4.1f 平均体重＝%5.1f\n", (float)attl/i, httl/i);
	printf("入力件数＝%d\n", i);
	
	return 0;
}