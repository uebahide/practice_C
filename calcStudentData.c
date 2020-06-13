#include<stdio.h>

#define N 5                                       /* 科目数                        */

typedef struct
{
	int number;
	char name[10];
	int score[5];
	int total;
	float average;
	
}Student;

void calcStudentData(Student *p, int length);

int main(void)
{
		int I, j;                                   /* ループカウンタ               */
		
		/* Student構造体配列*/
		Student stuArray[]=
		{
			{1, "Kumagai"  , {95, 90, 70, 60, 90}},
			{2, "Takahashi", {90, 80, 80, 95, 89}},
			{3, "Nakamura" , {90, 72, 98, 88, 74}},
			{4, "Ota"      , {98, 72, 75, 80, 99}},
			{5, "Nagatomo" , {91, 70, 80, 95, 87}}
		};
		
		/* 合計と平均を求める関数の呼び出し */
		calcStudentData(stuArray, sizeof(stuArray)/sizeof(stuArray[0]));
		
		/* 各学生のテスト結果を表示 */
		printf("No  名前              国語  英語  数学  理科  社会  合計  平均\n");
		printf("--------------------------------------------------------------\n");
		
		
		for(I=0; I<sizeof(stuArray)/sizeof(stuArray[0]); I++)
		{
			printf("%d   %-9s         ", stuArray[I].number, stuArray[I].name);
			
			for(j=0; j<N; j++)
			{
				printf("%d    ", stuArray[I].score[j]);
			}
			
			printf("%d  %5.1f\n", stuArray[I].total, stuArray[I].average);
			
		}
		
		return 0;
}

void calcStudentData(Student* p, int length)
{
	int I, j;
	
	for(I=0; I<length; I++)
	{
		for(j=0; j<N; j++)
		{
			(p+I)->total += (p+I)->score[j];
		}
	
		(p+I)->average = (p+I)->total/N;
	}
}