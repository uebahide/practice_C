#include<stdio.h>

void sort(int *data, int i);

int main(void)
{
	int data[15];
	int i, j;
	
	printf("***データに0を入力すると終了します***\n");
	
	for(i=0; i<15; i++)
	{
		printf("data[%d]===>", i);
		scanf("%d", &data[i]);
		
		if(data[i]==0)
		{
			break;
		}
	}
	
	sort(data, i);
	
	printf("***結果***\n");
	
	for(j=0; j<i; j++)
	{
		printf("data[%d]=%d\n", j, data[j]);
	}
	
}



void sort(int *data, int i)
{
	int j, k, work;
		
	for(j=0; j<i-1; j++)
	{
		for(k=j+1; k<i; k++)
		{
			if(*(data+j)<*(data+k))
			{
				work=*(data+j);
				*(data+j)=*(data+k);
				*(data+k)=work;
			}
		}
	}
}

