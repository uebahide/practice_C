#include<stdio.h>

int main(void)
{
	int i=0, count, k=0;
	int data[15];
	
	printf("***�f�[�^��0����͂���ƏI�����܂�***\n");
	
	while(1)
	{
		printf("data[%d]===>", i);
		scanf("%d", &data[i]);
		
		count=i;
		
		if(data[i]==0)
		{
			break;	
		}
		
		i++;
	}
	
	
	printf("***����***\n");
	
	for(i=0; i<count; i++)
	{
		printf("data[%d]��%d\n", i, data[i]);	
	}
	
	return 0;	
}