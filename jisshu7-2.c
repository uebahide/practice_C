#include<stdio.h>
#include<string.h>

int main(void)
{
	int cnt;
	int f=0;
	char data[100];
	char rireki[100];
	
	rireki[0]='\0';
	
	for(cnt=0; cnt<3; cnt++)
	{
		printf("暗証番号(4桁)＝＝＝>");
		scanf("%s", data);
		
		if(strlen(data)==4)
		{
			strcat(rireki, data);
		}
		else
		{
			strcat(rireki, "ERROR");
		}
		
		if(strcmp(data,"1234")==0)
		{
			printf("パスワード解除成功！\n");
			f++;
			break;
		}
		else
		{
			strcat(rireki, " ");
		}
		
	}
	
	if(cnt==3)
	{
		printf("パスワード解除失敗！\n");
	}
	
	printf("入力データ＝%s\n", rireki);
	
	return 0;
	
}