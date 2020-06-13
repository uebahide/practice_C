#include<stdio.h>

#define N 5                                                   /* �Ȗڐ�                   */

/* �\���̂̐錾 */
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
	int i;                                                     /* ���[�v�J�E���^                        */
	int stuNum;                                                /* ���͂��ꂽ�w���ԍ����i�[����ϐ�      */
	Student* p;                                                /* �֐�����̖߂�l���i�[����|�C���^�ϐ�*/
	
	/* Student�\���̔z�� */                                                       
	Student stuArray[]=
	{
			{1, "Kumagai"  , {95, 90, 70, 60, 90}, 405, 81.0f},    
			{2, "Takahashi", {90, 80, 80, 95, 89}, 434, 86.8f},
			{3, "Nakamura" , {90, 72, 98, 88, 74}, 422, 84.4f},
			{4, "Ota"      , {98, 72, 75, 80, 99}, 424, 84.8f},
			{5, "Nagatomo" , {91, 70, 80, 95, 87}, 423, 84.6f}
	};
	
	printf("�w���ԍ�����͂��Ă��������F");
	scanf("%d", &stuNum);
	if(stuNum<1)
	{
		printf("���͒l������������܂���B\n");
		exit(-1);
	}
	
	/* �w��������������֐��̌Ăяo�� */
	p=searchStudentData(stuArray, stuNum, sizeof(stuArray)/sizeof(stuArray[0]));
	
	
	if(p==NULL)
	{
		printf("���͂��ꂽ�w���ԍ��̏�񂪌�����܂���B\n");
	}
	else
	{
	/* �������ʂ̕\�� */
		printf("No  ���O              ����  �p��  ���w  ����  �Љ�  ���v  ����\n");
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
	int i;                                                                          /*���[�v�J�E���^                               */
	Student* stuP=NULL;                                                             /* �߂�l���i�[����|�C���^�ϐ��iNULL�ŏ������j*/
	
	/*��������*/
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