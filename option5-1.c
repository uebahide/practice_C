#include<stdio.h>

int main(void)
{
	int i, j, k, work, p;
	int data[15];
	
	printf("***�f�[�^��0����͂���Ɠ��͏������I�����܂�***\n");
	
	for(i=0; i<15; i++)
	{
		printf("�f�[�^����͂��Ă�����������>");
		scanf("%d", &data[i]);
	
		if(data[i]==0)
		{
			break;
		}
	}
	
	printf("\n");
	
	while(p!=0)
	{
		printf("�I��(0) �~��(1) ����(2) \n�Ђ傤�����@��I�����Ă������� ==> ");
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
				
				printf("***����***\n");
				
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
				
				printf("***����***\n");
				
				for(j=0; j<i; j++)
				{
					printf("%d  ", data[j]);
				}
				
				printf("\n");
				
				break;
			
			case 0:
				printf("***�I�����܂�***\n");
				break;
		}
	}
}