#include<stdio.h>

float average(int *a, int size);

int main(void)
{
	int seisu[5]={75, 82, 59, 38, 62};         /* int �^�z��                      */
	int i;                                     /* ���[�v�J�E���^                  */
	int length;                                /* �z��̗v�f��                    */
	float result;                              /* �v�Z����                        */
	
	length=sizeof(seisu)/sizeof(seisu[0]);     /* �z��v�f���̎Z�o                */
	
	result=average(seisu, length);             /* ���ς����߂�֐��̌Ăяo��      */
	
	
	/* �z��v�f�̕\�����[�v */
	printf("���l�F"); 
	for(i=0; i<length; i++)
	{
		printf("%d ", seisu[i]);
	}
	printf("\n");
	
	printf("���ρF%2.1f\n", result);           /* ���ϒl�̕\��                    */
	
	return 0;
}


float average(int *a, int size)
{
	int i;                                     /* ���[�v�J�E���^                   */
	float ttl=0;                               /* �z��̗v�f�̍��v�l���i�[����ϐ� */
	float ave;                                 /* �z��̗v�f�̕��ϒl���i�[����ϐ� */
	
	/* ���v�����߂郋�[�v */
	for(i=0; i<size; i++)
	{
		ttl+=*(a+i);
	}
	
	ave=ttl/size;                              /* ���ϒl�̎Z�o                     */
	
	return ave;                                /* �߂�l                           */
}