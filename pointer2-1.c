#include<stdio.h>

float average(int *a, int size);

int main(void)
{
	int seisu[5]={75, 82, 59, 38, 62};         /* int 型配列                      */
	int i;                                     /* ループカウンタ                  */
	int length;                                /* 配列の要素数                    */
	float result;                              /* 計算結果                        */
	
	length=sizeof(seisu)/sizeof(seisu[0]);     /* 配列要素数の算出                */
	
	result=average(seisu, length);             /* 平均を求める関数の呼び出し      */
	
	
	/* 配列要素の表示ループ */
	printf("数値："); 
	for(i=0; i<length; i++)
	{
		printf("%d ", seisu[i]);
	}
	printf("\n");
	
	printf("平均：%2.1f\n", result);           /* 平均値の表示                    */
	
	return 0;
}


float average(int *a, int size)
{
	int i;                                     /* ループカウンタ                   */
	float ttl=0;                               /* 配列の要素の合計値を格納する変数 */
	float ave;                                 /* 配列の要素の平均値を格納する変数 */
	
	/* 合計を求めるループ */
	for(i=0; i<size; i++)
	{
		ttl+=*(a+i);
	}
	
	ave=ttl/size;                              /* 平均値の算出                     */
	
	return ave;                                /* 戻り値                           */
}