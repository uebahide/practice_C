#include<stdio.h>

# define N 5                                            /* �Ȗڐ�                */

void total(int **p, int size);

int main(void)
{
	int a[6]={75, 82, 59, 38, 61, 0};                   /* A����̊w�ȃe�X�g��� */ 
	int b[6]={70, 77, 54, 33, 46, 0};                   /* B����̊w�ȃe�X�g��� */ 
	int c[6]={80, 87, 64, 43, 66, 0};					/* C����̊w�ȃe�X�g��� */
	int d[6]={85, 92, 69, 48, 71, 0};                   /* D����̊w�ȃe�X�g��� */   
	int e[6]={90, 90, 90, 90, 90, 0};                   /* E����̊w�ȃe�X�g��� */  
	int *p[]={a, b, c, d, e};                           /* �|�C���^ */
	int i, j;                                           /* ���[�v�J�E���^ */
	int length;                                         /* �z��̗v�f�� */  
	
	/* �z��v�f���̎Z�o */
	length=sizeof(p)/sizeof(p+0);
	
	/* �w�ȃe�X�g�̍��v�_�����߂�֐��̌Ăяo�� */
	total(p, length);
	
	/* �w�ȃe�X�g���̕\�� */
	printf("      :�� �p �� �� �� ���v\n");
	printf("--------------------------\n");
	for(i=0; i<length; i++)
	{
		printf("%d�l�� :", i+1);
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
	int i, j;                                           /* ���[�v�J�E���^ */
	int ttl;                                          /* ���v */
	
	/* ���v���Z�o���郋�[�v */
	for(i=0; i<size; i++)
	{
		for(j=0, ttl=0; j<N; j++)
		{
			ttl+=*(*(p+i)+j);
		}
		*(*(p+i)+j)=ttl;
	}
}