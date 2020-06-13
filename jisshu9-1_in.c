#include "option9-1.h"

int in(stuct DATA* data)
{
	int i;
	
	for(i=0; i<MAX_CNT; i++)
	{
		printf("[ %d]番目の名前(0入力終了)＝＝＞", i+1);
		scanf("%s", (data+i)->name);
		
		if((data+i)->name[0]=='0')
		{
			break;
		}
		
		printf("[ %d]番目の年齢＝＝＞", i+1);
		scanf("%d", &(data+i)->age);
		
		printf("[ %d]番目の身長＝＝＞", i+1);
		scanf("%f", &(data+i)->height);
	}
	
	return i;
}