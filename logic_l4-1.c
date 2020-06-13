#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define F_NAME "score.dat"

typedef struct 
{
	char class;
	int number;
	char name[10+1];
	int engscore;
	int matscore;
	int lanscore;
}record;


int main(void)
{
	record IN;             /*�_�����R�[�hIN           */
	record OUT;            /*�_�����R�[�hOUT          */
	int EG, MG, LG;        /* �Ȗڂ��Ƃ̍��v�_��      */
	int EH, MH, LH;        /* �Ȗڂ��Ƃ̕��ϓ_��      */
	int cnt;               /* ���[�v�J�E���^          */
	char work;              /* �ޔ�̈�                */
	char F[100];           /* �I���t���O              */
	FILE* fp;              /* �t�@�C���\���̂̃|�C���^*/

	/* �t�@�C�����J����1���R�[�h��ǂݍ��ޑO���� */
	if((fp=fopen(F_NAME, "r"))==NULL)
	{
		printf("�t�@�C�����J���܂���B\n");
		exit(1);
	}
	
	/* �t�@�C����1���R�[�h�ǂݍ��� */
	if((fscanf(fp, "%c%2d%10s%3d%3d%3d%*c", &IN.class, &IN.number, IN.name, &IN.engscore, &IN.matscore, &IN.lanscore))==EOF)
	{
		strcpy(F, "EOF");
	}
	
	
	/* �������\��  */
	printf("�N���X     �p��   ���w   ����\n");
	
	/* �又�����[�v���J�n */
	while(strcmp(F, "EOF")!=0)
	{
	
		/* �ȍ~���又�� */
		work=IN.class;		                   			/* ���v�ƕ��ς��v�Z����ŏ��̃N���X��work�ɑ�� */  
		cnt=0;											/* ���[�v�J�E���^��0�ŏ�����                    */
		EG=MG=LG=0;                                     /* �Ȗڂ��Ƃ̍��v�_����0�ŏ�����                */
		EH=MH=LH=0;                                     /* �Ȗڂ��Ƃ̕��ϓ_����0�ŏ�����                */
		/* �W�v���[�v�J�n */
		while(strcmp(F, "EOF")!=0 && IN.class==work)
		{
			EG += IN.engscore;
			MG += IN.matscore;
			LG += IN.lanscore;
			
			
			
			cnt++;                                       /* �t�@�C����1���R�[�h�i�߂�                    */
			
			/* �t�@�C����1���R�[�h�ǂݍ���*/
			if((fscanf(fp, "%c%2d%10s%3d%3d%3d%*c", &IN.class, &IN.number, IN.name, &IN.engscore, &IN.matscore, &IN.lanscore))==EOF)
			{
				strcpy(F, "EOF");
			}
		}
		
		/* �Ȗڂ��Ƃ̕��ϓ_�������߂� */
		EH = EG/cnt;
		MH = MG/cnt;
		LH = LG/cnt;
		
		/* �������\�� */
		
		printf("%c    %d   %d   %d\n", work, EH, MH, LH);
	}
	
	fclose(fp);
	
	return 0;
}





