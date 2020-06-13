#include<stdio.h>
#include<string.h>

#define MAX_CNT 100

struct DATA 
{
	char name[MAX_CNT];
	int age;
	float height;
};

int in(struct DATA* p);
void sort(struct DATA* p, int cnt);
void out(struct DATA* p, int cnt);

int main(void)
{
	struct DATA data[10];
	
	int cnt;
	
	cnt=in(data);
	
	sort(data, cnt);
	
	out(data, cnt);
	
	return 0;
}

int in(struct DATA* p)
{
	int cnt;
	
	for(cnt=0; cnt<10; cnt++)
	{
		printf("[ %d]�Ԗڂ̖��O(0���͏I��)����>", cnt+1);
		scanf("%s", (p+cnt)->name);
		
		if( (p+cnt)->name[0] == '0')
		{
			break;
		}
		
		printf("[ %d]�Ԗڂ̔N���>", cnt+1);
		scanf("%d", &(p+cnt)->age);
		
		printf("[ %d]�Ԗڂ̐g������>", cnt+1);
		scanf("%f", &(p+cnt)->height);
	}
	
	printf("\n");
	
	return cnt;
}

void sort(struct DATA* p, int cnt)
{
	int i, j;
	struct DATA work;
	
	for(i=0; i<cnt-1; i++)
	{
		for(j=0; j<cnt; j++)
		{
			if( ((p+i)->age) < ((p+j)->age) )
			{
				work=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=work;
			}
		}
	}
}

void out(struct DATA* p, int cnt)
{
	int i;
	float attl=0, httl=0;
	
	
	printf("���O       �N��   �g��\n");
	
	for(i=0; i<cnt; i++)
	{
		printf("%s            %d     %5.1f\n", (p+i)->name, (p+i)->age, (p+i)->height);
		
		attl+=(p+i)->age;
		httl+=(p+i)->height;
	}
	
	printf("\n");
	printf("���ϔN�%5.1f   ���ϐg����%5.1f\n", (float)attl/cnt, httl/cnt);
	printf("���͌�����%d��\n", cnt);
}
