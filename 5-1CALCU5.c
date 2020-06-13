#include<stdio.h>
#include<stdlib.h>

#define F_NAME1 "change.dat"
#define F_NAME2 "rireki.dat"

/* �t�@�C��"rireki.dat"�ɒǉ�����f�[�^���i�[���邽�߂̍\����*/
struct RIREKI
{
	int fare;
	int change;
	int y500;
	int y100;
	int y50;
	int y10;
};

int main(void)
{
	struct RIREKI rireki;                                             /* �����t�@�C���ɏ������ރf�[�^���i�[����\���̕ϐ�    */
	int m[4];                                                         /* �t�@�C��"change.dat"�̃��R�[�h��ǂݍ��ނ��߂̕ϐ�  */
	FILE* fp1;                                                        /* �t�@�C��"change.dat"�p�̃t�@�C���|�C���^            */
	FILE* fp2;                                                        /* �t�@�C��"rireki.dat"�p�̃t�@�C���|�C���^            */
	
	if((fp1=fopen(F_NAME1, "r"))==NULL)
	{
		printf("�t�@�C�����J���܂���B\n");
		exit(1);
	}
	
	fscanf(fp1, "%3d%3d%3d%3d%*c", &m[0], &m[1], &m[2], &m[3]);       /* �ޑK�̊e������ǂݍ��ޏ���                          */
	
	/* �又�� */
	while(1)
	{
		
		rireki.y500=rireki.y100=rireki.y50=rireki.y10=0;             /* ���ނɕK�v�ȒޑK�̊e������0���ɏ�����                */
		
		printf("�w�����z������");
		scanf("%d", &rireki.fare);
		
		/* �w�����z��0����͂ŏI�� */
		if(rireki.fare==0)
		{
			break;
		}
		
		rireki.change=1000-rireki.fare;
		
		/* �ޑK�v�Z���� */
		if(rireki.change/500 <= m[0])
		{
			rireki.y500=rireki.change/500;
		}
		
		if((rireki.change-500*rireki.y500)/100 <= m[1])
		{
			rireki.y100=(rireki.change-500*rireki.y500)/100;
		}
		
		if((rireki.change-500*rireki.y500-100*rireki.y100)/50 <= m[2])
		{
			rireki.y50=(rireki.change-500*rireki.y500-100*rireki.y100)/50;
		}
		
		if((rireki.change-500*rireki.y500-100*rireki.y100-50*rireki.y50)/10 <= m[3])
		{
			rireki.y10=(rireki.change-500*rireki.y500-100*rireki.y100-50*rireki.y50)/10;
		}
		
		/* �ޑK�̊e�������X�V */
		if(rireki.change ==  500*rireki.y500+100*rireki.y100+50*rireki.y50+10*rireki.y10)
		{
			m[0] -= rireki.y500;
			m[1] -= rireki.y100;
			m[2] -= rireki.y50;
			m[3] -= rireki.y10;
		}else{
			printf("�ޑK�؂�ł��B\n");
		}
	
		if((fp2=fopen(F_NAME2, "a"))==NULL)
		{
			printf("�t�@�C�����J���܂���B\n");
			exit(1);
		}
	
		/* �t�@�C��"rireki.dat"�Ƀf�[�^��ǉ����鏈�� */
		fprintf(fp2, "%3d%3d%3d%3d%3d%3d\n", rireki.fare, rireki.change, rireki.y500, rireki.y100, rireki.y50, rireki.y10);
	
		fclose(fp2);
	}
	
	fclose(fp1);

	return 0;
}