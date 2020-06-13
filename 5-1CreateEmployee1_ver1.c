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
	int count;                           /* �v�f��           */
	Employee* p;                         /* �\���̔z��̐擪 */
	int i;                               /* ���[�v�J�E���^   */
	
	printf("�v�f������");                /* �v�f���̊l��     */
	scanf("%d", &count);
	
	p=createEmployee(count);             /* �̈�𓮓I�ɍ쐬 */
		
	/* �e�̈�ɒl��ݒ� */
	for(i=0; i<count; i++)
	{
		setEmployee(p+i);
	}
	
	/* �e�̈�̒l���o�� */
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
	printf("#����--------------------------#\n");
	printf("��������");
	scanf("%s", p->name);
	printf("��������");
	scanf("%s", p->section);
	printf("�d�b����");
	scanf("%s", p->phone);
	printf("#------------------------------#\n");
}

void printEmployee(Employee* p)
{
	printf("#�o��**************************#\n");
	printf("�����F%s\n", p->name);
	printf("�����F%s\n", p->section);
	printf("�d�b�F%s\n", p->phone);
	printf("#******************************#\n");
}