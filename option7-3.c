#include<stdio.h>
#include<string.h>

#define MAX_CNT 100

int tannsaku(char* pmoji1, char* pmoji2);

int main(void)
{
	int f;

	char moji1[MAX_CNT];
	char moji2[MAX_CNT];
	
	printf("moji1‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
	scanf("%s", &moji1);
	
	printf("moji2‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
	scanf("%s", &moji2);
	
	f=tannsaku(moji1, moji2);
	
	if(f==1)
	{
		printf("moji2‚Ímoji1‚ÉŠÜ‚Ü‚ê‚é\n");
	}
	
	else
	{
		printf("moji2‚Ímoji1‚ÉŠÜ‚Ü‚ê‚È‚¢\n");
	}
	
	return 0;
}

int tannsaku(char* pmoji1, char* pmoji2)
{
	int i, j;
	int f=0;
	
	for(i=0; i<strlen(pmoji1)-strlen(pmoji2)+1; i++)
	{
		for(j=0 ; j<strlen(pmoji2); j++)
		{
			if(*(pmoji1+i+j) != *(pmoji2+j))
			{
				break;
			}
		} 
		
		if(j==strlen(pmoji2))
		{
			f=1;
			break;
		}
	}
	
	return f;
}
