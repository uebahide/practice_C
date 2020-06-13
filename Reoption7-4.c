#include<stdio.h>
#include<string.h>

struct DATA
{
	char name[100];
	int age;
	float height;
};

int in(struct DATA* data);
void sort(struct DATA* data, int i);
void out(struct DATA* data, int i);

int main(void)
{
	struct DATA data[10];
	
	int i;
	
	i=in(data);
	sort(data, i);
	out(data, i);
	
	return 0;
}

int in(struct DATA* data)
{
	int i;
	
	for(i=0; i<10; i++)
	{
		printf("[ %d]�Ԗڂ̖��O(0���͏I��)����>", i+1);
		scanf("%s", (data+i)->name);
	
		if((data+i)->name[0] == '0'){break;}
		
		printf("[ %d]�Ԗڂ̔N���>", i+1);
		scanf("%d", &(data+i)->age);
		
		printf("[ %d]�Ԗڂ̐g������>", i+1);
		scanf("%f", &(data+i)->height);
	}
	
	return i;
}

void sort(struct DATA* data, int i)
{
	int j, k;
	struct DATA work;
	
	for(j=0; j<i-1; j++)
	{
		for(k=j+1; k<i; k++)
		{
			if((data+j)->age < (data+k)->age)
			{
				work=*(data+j);
				*(data+j)=*(data+k);
				*(data+k)=work;
			}
		}
	}
}

void out(struct DATA* data, int i)
{
	int j;
	float attl=0;
	float httl=0;
	
	printf("���O      �N��   �g��\n");
	
	for(j=0; j<i; j++)
	{
		printf("%s       %d   %5.1f\n", (data+j)->name, (data+j)->age, (data+j)->height);
		
		attl+=(data+j)->age;
		httl+=(data+j)->height;
	}
	
	printf("���ϔN�%5.1f  ���ϔN�%5.1f\n", (float)attl/i, httl/i);
	printf("���͌�����%d��", i);
}