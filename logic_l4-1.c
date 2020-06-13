#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define F_NAME "score.dat"

typedef struct 
{
	char class;
	int number;
	char name[10+1];
	int engscore;
	int matscore;
	int lanscore;
}record;


int main(void)
{
	record IN;             /*点数レコードIN           */
	record OUT;            /*点数レコードOUT          */
	int EG, MG, LG;        /* 科目ごとの合計点数      */
	int EH, MH, LH;        /* 科目ごとの平均点数      */
	int cnt;               /* ループカウンタ          */
	char work;              /* 退避領域                */
	char F[100];           /* 終了フラグ              */
	FILE* fp;              /* ファイル構造体のポインタ*/

	/* ファイルを開いて1レコードを読み込む前処理 */
	if((fp=fopen(F_NAME, "r"))==NULL)
	{
		printf("ファイルを開けません。\n");
		exit(1);
	}
	
	/* ファイルを1レコード読み込む */
	if((fscanf(fp, "%c%2d%10s%3d%3d%3d%*c", &IN.class, &IN.number, IN.name, &IN.engscore, &IN.matscore, &IN.lanscore))==EOF)
	{
		strcpy(F, "EOF");
	}
	
	
	/* 文字列を表示  */
	printf("クラス     英語   数学   国語\n");
	
	/* 主処理ループを開始 */
	while(strcmp(F, "EOF")!=0)
	{
	
		/* 以降が主処理 */
		work=IN.class;		                   			/* 合計と平均を計算する最初のクラスをworkに代入 */  
		cnt=0;											/* ループカウンタを0で初期化                    */
		EG=MG=LG=0;                                     /* 科目ごとの合計点数を0で初期化                */
		EH=MH=LH=0;                                     /* 科目ごとの平均点数を0で初期化                */
		/* 集計ループ開始 */
		while(strcmp(F, "EOF")!=0 && IN.class==work)
		{
			EG += IN.engscore;
			MG += IN.matscore;
			LG += IN.lanscore;
			
			
			
			cnt++;                                       /* ファイルを1レコード進める                    */
			
			/* ファイルを1レコード読み込む*/
			if((fscanf(fp, "%c%2d%10s%3d%3d%3d%*c", &IN.class, &IN.number, IN.name, &IN.engscore, &IN.matscore, &IN.lanscore))==EOF)
			{
				strcpy(F, "EOF");
			}
		}
		
		/* 科目ごとの平均点数を求める */
		EH = EG/cnt;
		MH = MG/cnt;
		LH = LG/cnt;
		
		/* 文字列を表示 */
		
		printf("%c    %d   %d   %d\n", work, EH, MH, LH);
	}
	
	fclose(fp);
	
	return 0;
}





