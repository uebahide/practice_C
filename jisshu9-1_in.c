#include "option9-1.h"

int in(stuct DATA* data)
{
	int i;
	
	for(i=0; i<MAX_CNT; i++)
	{
		printf("[ %d]�Ԗڂ̖��O(0���͏I��)������", i+1);
		scanf("%s", (data+i)->name);
		
		if((data+i)->name[0]=='0')
		{
			break;
		}
		
		printf("[ %d]�Ԗڂ̔N�����", i+1);
		scanf("%d", &(data+i)->age);
		
		printf("[ %d]�Ԗڂ̐g��������", i+1);
		scanf("%f", &(data+i)->height);
	}
	
	return i;
}