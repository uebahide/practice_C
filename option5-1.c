#include<stdio.h>

int main(void)
{
	int i, j, k, work, p;
	int data[15];
	
	printf("***データに0を入力すると入力処理を終了します***\n");
	
	for(i=0; i<15; i++)
	{
		printf("データを入力してください＝＝>");
		scanf("%d", &data[i]);
	
		if(data[i]==0)
		{
			break;
		}
	}
	
	printf("\n");
	
	while(p!=0)
	{
		printf("終了(0) 降順(1) 昇順(2) \nひょうじ方法を選択してください ==> ");
		scanf("%d", &p);
		
		switch(p)
		{
			case 1:
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
					printf("%d  ", data[j]);
				}
				
				printf("\n");
				
				break;
			
			case 2:
				for(j=0; j<i-1; j++)
				{
					for(k=j+1; k<i; k++)
					{
						if(data[j]>data[k])
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
					printf("%d  ", data[j]);
				}
				
				printf("\n");
				
				break;
			
			case 0:
				printf("***終了します***\n");
				break;
		}
	}
}