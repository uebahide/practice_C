#include<stdio.h>

# define N 5                                            /* 科目数                */

void total(int **p, int size);

int main(void)
{
	int a[6]={75, 82, 59, 38, 61, 0};                   /* Aさんの学科テスト情報 */ 
	int b[6]={70, 77, 54, 33, 46, 0};                   /* Bさんの学科テスト情報 */ 
	int c[6]={80, 87, 64, 43, 66, 0};					/* Cさんの学科テスト情報 */
	int d[6]={85, 92, 69, 48, 71, 0};                   /* Dさんの学科テスト情報 */   
	int e[6]={90, 90, 90, 90, 90, 0};                   /* Eさんの学科テスト情報 */  
	int *p[]={a, b, c, d, e};                           /* ポインタ */
	int i, j;                                           /* ループカウンタ */
	int length;                                         /* 配列の要素数 */  
	
	/* 配列要素数の算出 */
	length=sizeof(p)/sizeof(p+0);
	
	/* 学科テストの合計点を求める関数の呼び出し */
	total(p, length);
	
	/* 学科テスト情報の表示 */
	printf("      :国 英 数 理 社 合計\n");
	printf("--------------------------\n");
	for(i=0; i<length; i++)
	{
		printf("%d人目 :", i+1);
		for(j=0; j<N+1; j++)
		{
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
	
	return 0;
}

void total(int **p, int size)
{
	int i, j;                                           /* ループカウンタ */
	int ttl;                                          /* 合計 */
	
	/* 合計を算出するループ */
	for(i=0; i<size; i++)
	{
		for(j=0, ttl=0; j<N; j++)
		{
			ttl+=*(*(p+i)+j);
		}
		*(*(p+i)+j)=ttl;
	}
}