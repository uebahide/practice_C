#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char name[40];
	char section[40];
	char phone[40];
}Employee;

void setEmployee(Employee* p);
void printEmployee(Employee* p);
Employee* createEmployee(int size);

int main(void)
{
	int count;                           /* 要素数           */
	Employee* p;                         /* 構造体配列の先頭 */
	int i;                               /* ループカウンタ   */
	
	printf("要素数＝＞");                /* 要素数の獲得     */
	scanf("%d", &count);
	
	p=createEmployee(count);             /* 領域を動的に作成 */
		
	/* 各領域に値を設定 */
	for(i=0; i<count; i++)
	{
		setEmployee(p+i);
	}
	
	/* 各領域の値を出力 */
	for(i=0; i<count; i++)
	{
		printEmployee(p+i);
	}
	
	free(p);
	
	return 0;
}

Employee* createEmployee(int size)
{
	Employee* p;
	
	p=(Employee*)malloc(sizeof(Employee)*size);
	
	return p;
}

void setEmployee(Employee* p)
{
	printf("#入力--------------------------#\n");
	printf("氏名＝＞");
	scanf("%s", p->name);
	printf("部署＝＞");
	scanf("%s", p->section);
	printf("電話＝＞");
	scanf("%s", p->phone);
	printf("#------------------------------#\n");
}

void printEmployee(Employee* p)
{
	printf("#出力**************************#\n");
	printf("氏名：%s\n", p->name);
	printf("部署：%s\n", p->section);
	printf("電話：%s\n", p->phone);
	printf("#******************************#\n");
}