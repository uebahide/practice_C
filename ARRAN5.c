#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME1 "dist.dat"
#define F_NAME2 "fare.dat"

int main(void)
{
	/* 距離ファイルのデータを格納する配列群*/
	char  sta[19][12+1];                           /* 駅名を格納する配列                  */
	float dis[19];                                /* 外回りの距離を格納する配列          */
	
	/* 運賃ファイルのデータを格納する配列群*/
	int x[14];                                    /* 距離の代表値を格納する配列          */
	int fare[14];                                 /* 運賃を格納する配列                  */
	
	char josya[12+1];                             /* 乗車駅名を格納する変数              */
	char gesya[12+1];                             /* 下車駅名を格納する変数              */
	
	float jdis;                                   /* 乗車駅の距離                        */
	float gdis;                                   /* 下車駅の距離                        */
	float d;                                      /* 乗車駅から下車駅までの最短距離      */
	int dint;
	int key;                                      /* ファイル"fare.dat"検索キー          */
	
	int i;                                        /* ループカウンタ                      */
	
	FILE* fp1;                                    /* ファイル"dist.dat"のファイルポインタ*/
	FILE* fp2;                                    /* ファイル"fare.dat"のファイルポインタ*/
	
	/* ファイルオープン */
	if((fp1=fopen(F_NAME1, "r"))==NULL)
	{
		printf("ファイルdist.datを開けません。\n");
		exit(1);
	}
	
	/* ファイルオープン */
	if((fp2=fopen(F_NAME2, "r"))==NULL)
	{
		printf("ファイルfare.datを開けません。\n");
		exit(1);
	}
	
	/* dist.datを読み込む */
	i=0;
	while((fscanf(fp1, "%s%4f%*c",&sta[i][0] , &dis[i]))!=EOF)
	{
		i++;
	}
	
	/* fare.datを読み込む */
	i=0;
	while((fscanf(fp2, "%2d%4d%*c", &x[i], &fare[i]))!=EOF)
	{
		i++;	
	}
	
	/* 主処理ループ */
	while(1)
	{
		/* 乗車駅名を入力 */
		printf("乗車駅＝＝＞(END入力終了)");
		scanf("%s", josya);
		if(strcmp(josya, "END")==0)
		{
			break;
		}
		
		/* 下車駅名を入力 */
		printf("下車駅＝＝＞");
		scanf("%s", gesya);
		
		/* dist.datから乗車駅名の距離を検索 */
		for(i=0; i<19; i++)
		{
			if(strcmp(josya, sta[i])==0)
			{
				break;
			}
		}
		jdis=dis[i];
		
		/* dist.datから下車駅名の距離を検索 */
		for(i=0; i<19; i++)
		{
			if(strcmp(gesya, sta[i])==0)
			{
				break;
			}
		}
		gdis=dis[i];
		
		/* 内回りと外回りを比較して小さいほうをdに代入 */
		if(jdis>gdis)
		{
			if( (21.7-(jdis-gdis)) < (jdis-gdis) )
			{
				d=21.7-(jdis-gdis);
			}
			else
			{
				d=jdis-gdis;
			}
		}
		else
		{
			if( (21.7-(gdis-jdis)) < (gdis-jdis) )
			{
				d=21.7-(gdis-jdis);
			}
			else
			{
				d=gdis-jdis;
			}
		}
		
		/* fare.datのキー値と比較するkeyの値を決定する処理 */
		dint=(int)d;                                                       /* dの整数部のみをdintに代入する */
		if(dint<=40)
		{
			if(dint<=20)
			{
				if(dint<=10)
				{
					if(0<=dint&&dint<=3)
					{
						key=3;
					}
					else if(3<dint&&dint<=6)
					{
						key=6;
					}
					else
					{
						key=10;
					}
				}
				else
				{
					if(10<dint&&dint<=15)
					{
						key=15;
					}
					else
					{
						key=20;
					}
				}
			}
		
			else
			{
				if(dint<=30)
				{
					if(20<dint&&dint<=25)
					{
						key=25;
					}
					else
					{
						key=30;
					}
				}
				else
				{
					if(30<dint&&dint<=35)
					{
						key=35;
					}
					else
					{
						key=40;
					}
				}
			}
		}
		else
		{
			if(60<=dint)
			{
				if(40<dint&&dint<=45)
				{
					key=45;
				}
				else if(45<dint&&dint<=50)
				{
					key=50;
				}
				else
				{
					key=60;
				}
			}
			else
			{
				if(60<dint&&dint<=70)
				{
					key=70;
				}
				else
				{
					key=80;
				}
			}
		}
	
		/* keyの値とfare.datのキー値を比較して運賃を検索 */
		for(i=0; i<14; i++)
		{
			if(key==x[i])
			{
				break;
			}
		}
		
		printf("距離＝%3.1f\n", d);
		printf("運賃＝%d\n", fare[i]);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}