#include<stdio.h>

int main(void)
{
	int i, j, k;
	int work;
	int data[15];
	
	printf("***データに0を入力すると終了します***\n");
	
	for(i=0; i<15; i++)
	{
		printf("data[%d]===>");
		scanf("%d", &data[i]);
		
		if(data[i]==0)
		{
			break;
		}
	}
	
	for(j=0; j<i-1; j++)
	{
		for(k=j+1; k<i; k++)
		{
			if(data[j]<data[k])
			{
				work=data[j];
				data[j]=data[k];
				data[k]=work;
			}
		}
	}
	
	printf("***結果***\n");
	
	for(j=0; j<i; j++)
	{
		printf("data[%d]=%d\n", j, data[j]);
	}
	
	return 0;
}