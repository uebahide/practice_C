#include<stdio.h>

int in(int *data);
void sort(int *data, int n);
void out(int *data, int n);

int main(void)
{
	int data[15];
	
	int i;
	
	printf("***�f�[�^��0����͂���Ɠ��͏������I�����܂�***\n");

	i=in(data);
	
	sort(data, i);
	
	out(data, i);
	
	return 0;
}


int in(int *data)
{
	int i;
	
	for(i=0; i<15; i++)
	{
		printf("�f�[�^����͂��Ă�������������>");
		scanf("%d", data+i);
		
		if(*(data+i)==0)
		{
			break;
		}
	}
	
	return i;
}

void sort(int *data, int i)
{
	int j, k;
	int work;
	
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


void out(int *data, int i)
{
	int p;
	int j;

	while(p!=0)
	{
		printf("�I��(0) �~��(1) ����(2)\n");
		printf("�\\�����@��I�����Ă�����������>");
		scanf("%d", &p);
	
		switch(p)
		{
			case 1:
				
				printf("***����***\n");
				
				for(j=0; j<i; j++)
				{
					printf("%d ", *(data+j));
				}
				
				printf("\n");
				
				break;
			
			case 2:
			
				printf("***����***\n");
			
				for(j=i-1; j>-1; j--)
				{
					printf("%d ", *(data+j));
				}
			
				printf("\n");
			
				break;
			
			case 0:
		
				printf("***�I�����܂�***\n");
				break;
		}
	}
}