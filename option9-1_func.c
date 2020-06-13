#include  "option9-1.h"

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

int out(struct DATA* data, int n)
{
	int i;
	float attl=0;
	float httl=0;
	
	printf("名前           年齢    身長\n");
	for(i=0; i<n; i++)
	{
		printf("%s        %d     %5.1f\n", (data+i)->name, (data+i)->age, (data+i)->height);
		
		attl+=(data+i)->age;
		httl+=(data+i)->height;
	}
	
	printf("平均年齢＝%5.1f  平均身長＝%5.1f\n", attl/i, httl/i);
	printf("入力件数＝%d件\n", i);
	
	return 0;
}

int sort(struct DATA* data, int n)
{
	int i, j;
	struct DATA work;
	
	for(i=0; i<n-1, i++)
	{
		for(j=i+1; j<n; j++)
		{
			if((data+i)->age < (data+j)->age)
			{
				work=*(data+i);
				*(data+i)=*(data+j);
				*(data+j)=work;
			}
		}
	}
	
	return 0;
}