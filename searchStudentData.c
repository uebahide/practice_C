#include<stdio.h>

#define N 5                                                   /* 科目数                   */

/* 構造体の宣言 */
typedef struct
{
	int number;
	char name[10];
	int score[5];
	int total;
	float average;
}Student;

Student* searchStudentData(Student* p, int stuNum, int length);

int main(void)
{
	int i;                                                     /* ループカウンタ                        */
	int stuNum;                                                /* 入力された学生番号を格納する変数      */
	Student* p;                                                /* 関数からの戻り値を格納するポインタ変数*/
	
	/* Student構造体配列 */                                                       
	Student stuArray[]=
	{
			{1, "Kumagai"  , {95, 90, 70, 60, 90}, 405, 81.0f},    
			{2, "Takahashi", {90, 80, 80, 95, 89}, 434, 86.8f},
			{3, "Nakamura" , {90, 72, 98, 88, 74}, 422, 84.4f},
			{4, "Ota"      , {98, 72, 75, 80, 99}, 424, 84.8f},
			{5, "Nagatomo" , {91, 70, 80, 95, 87}, 423, 84.6f}
	};
	
	printf("学生番号を入力してください：");
	scanf("%d", &stuNum);
	if(stuNum<1)
	{
		printf("入力値が正しくありません。\n");
		exit(-1);
	}
	
	/* 学生情報を検索する関数の呼び出し */
	p=searchStudentData(stuArray, stuNum, sizeof(stuArray)/sizeof(stuArray[0]));
	
	
	if(p==NULL)
	{
		printf("入力された学生番号の情報が見つかりません。\n");
	}
	else
	{
	/* 検索結果の表示 */
		printf("No  名前              国語  英語  数学  理科  社会  合計  平均\n");
		printf("--------------------------------------------------------------\n");
	
		printf("%d   %-9s         ", p->number, p->name);		
		for(i=0; i<N; i++)
		{
			printf("%d    ", p->score[i]);
		}
		printf("%d  %5.1f\n", p->total, p->average);
	}
	return 0;
}

Student* searchStudentData(Student* p, int stuNum, int length)
{
	int i;                                                                          /*ループカウンタ                               */
	Student* stuP=NULL;                                                             /* 戻り値を格納するポインタ変数（NULLで初期化）*/
	
	/*検索処理*/
	for(i=0; i<length; i++)
	{
		if(stuNum == (p+i)->number)
		{
			stuP=p+i;
			break;
		}
	}
	
	return stuP;
}