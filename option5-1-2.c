#include<stdio.h>

int main(void)
{
	int data[15];
	int cnt;
	int i, j;
	int work;
	int num;
	
	printf("***�f�[�^��0����͂���Ɠ��͏������I�����܂�***\n");
	
	for(cnt=0; cnt<15; cnt++)
	{
		printf("�f�[�^����͂��Ă�������������>");
		scanf("%d", &data[cnt]);
		
		if(data[cnt]==0)
		{
			break;
		}
	}
	
	for(i=0; i<cnt-1; i++)
	{
		for(j=i+1; j<cnt; j++)
		{
			if(data[i]<data[j])
			{
				work=data[i];
				data[i]=data[j];
				data[j]=work;
			}
		}
	}
	
	while(num!=0)
	{
	
		printf("�I��(0) �~��(1) ����(2)\n");
		printf("�\\�����@��I�����Ă�������������>");
		scanf("%d", &num);
	
		switch(num)
		{
			case 1:
				printf("***����***\n");
				
				for(i=0; i<cnt; i++)
				{
					printf("%d  ", data[i]);
				}
				
				printf("\n");
				break;
			
			case 2:
			
				printf("***����***\n");
				
				for(i=cnt-1; i>-1; i--)
				{
					printf("%d  ", data[i]);
				}
				
				printf("\n");
				break;
			
			case 0:
				break;
		}
	}
	
	return 0;
}
