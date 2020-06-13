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
		printf("[ %d]番目の名前(0入力終了)＝＝>", i+1);
		scanf("%s", data[i].name);
		
		
		if(data[i].name[0]=='0')
		{
			break;
		}
		
		printf("[ %d]番目の年齢＝＝>", i+1);
		scanf("%d", &data[i].age);

		attl+=data[i].age;
			
		printf("[ %d]番目の身長＝＝>", i+1);
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
	
	printf("名前       年齢   身長\n");
	
	for(j=0; j<i; j++)
	{
		printf("%s          %d    %5.1f\n", data[j].name, data[j].age ,data[j].height);
	}
	
	printf("平均年齢＝%5.1f  平均身長%5.1f\n", (float)attl/i, httl/i);
	printf("入力件数＝%d", i);
	
	return 0;	
}