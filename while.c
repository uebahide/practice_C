#include<stdio.h>

int main(void)
{
	int i=0, j=0, k=0;
	
	while(1)
	{
		i++;
		
		if(i>10)
		{
			break;
		}
	}
	
	while(0)
	{
		j++;
		
		if(j>10)
		{
			break;
		}
	}
	
	while(6)
	{
		k++;
		
		if(k>10)
		{
			break;
		}
	}
	
	printf("i=%d\n",i);
	printf("j=%d\n",j);
	printf("k=%d\n",k);
	
	return 0;
	
}