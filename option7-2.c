#include<stdio.h>
#include<string.h>

#define CNT_MAX 100

void renketu(char* pmoji1, char* pmoji2);

int main(void)
{
	char moji1[CNT_MAX];
	char moji2[CNT_MAX];

	printf("•¶š—ñ1‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
	scanf("%s", moji1);
	
	printf("•¶š—ñ2‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢>");
	scanf("%s", moji2);
	
	renketu(moji1, moji2);
	
	printf("˜AŒ‹Œã‚Ì•¶š—ñ%s\n", moji1);
	
	return 0;
}

void renketu(char* pmoji1, char* pmoji2)
{
	int i, j;
	
	for(i=0; i<CNT_MAX; i++)
	{
		if(*(pmoji1+i)=='\0')
		{
			break;
		}
	}
	
	for(j=0; j<CNT_MAX; j++, i++)
	{
		strcpy(pmoji1+i, pmoji2+j);
		
		if(*(pmoji2+j)=='\0')
		{
			break;
		}
	}
}	