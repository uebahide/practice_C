#include<stdio.h>
#include<stdlib.h>

#define F_NAME1 "change.dat"
#define F_NAME2 "rireki.dat"

struct RIREKI
{
	int fare;
	int change;
	int y500;
	int y100;
	int y50;
	int y10;
};

int main(void)
{
	struct RIREKI rireki;
	int m[4];
	FILE* fp1;
	FILE* fp2;
	
	if((fp1=fopen(F_NAME1, "r"))==NULL)
	{
		printf("ファイルを開けません。\n");
		exit(1);
	}
	
	fscanf(fp1, "%3d%3d%3d%3d%*c", &m[0], &m[1], &m[2], &m[3]);
	
	while(1)
	{
		printf("%d %d %d %d\n", m[0], m[1], m[2], m[3]);
		
		rireki.y500=rireki.y100=rireki.y50=rireki.y10=0;
		
		printf("購入金額＝＝＞");
		scanf("%d", &rireki.fare);
		
		if(rireki.fare==0)
		{
			break;
		}
		
		rireki.change=1000-rireki.fare;
		
		/* 釣銭計算処理 */
		if(rireki.change/500 <= m[0])
		{
			rireki.y500=rireki.change/500;
		}
		
		if((rireki.change-500*rireki.y500)/100 <= m[1])
		{
			rireki.y100=(rireki.change-500*rireki.y500)/100;
		}
		
		if((rireki.change-500*rireki.y500-100*rireki.y100)/50 <= m[2])
		{
			rireki.y50=(rireki.change-500*rireki.y500-100*rireki.y100)/50;
		}
		
		if((rireki.change-500*rireki.y500-100*rireki.y100-50*rireki.y50)/10 <= m[3])
		{
			rireki.y10=(rireki.change-500*rireki.y500-100*rireki.y100-50*rireki.y50)/10;
		}
		
		if(rireki.change ==  500*rireki.y500+100*rireki.y100+50*rireki.y50+10*rireki.y10)
		{
			m[0] -= rireki.y500;
			m[1] -= rireki.y100;
			m[2] -= rireki.y50;
			m[3] -= rireki.y10;
		}else{
			printf("釣銭切れです。\n");
		}
	
		if((fp2=fopen(F_NAME2, "a"))==NULL)
		{
			printf("ファイルを開けません。\n");
			exit(1);
		}
	
		fprintf(fp2, "%3d%3d%3d%3d%3d%3d\n", rireki.fare, rireki.change, rireki.y500, rireki.y100, rireki.y50, rireki.y10);
	
		fclose(fp2);
	}	

	return 0;
}