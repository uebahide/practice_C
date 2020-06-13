#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_NAME1 "dist.dat"
#define F_NAME2 "fare.dat"

int main(void)
{
	/* �����t�@�C���̃f�[�^���i�[����z��Q*/
	char  sta[19][12+1];                           /* �w�����i�[����z��                  */
	float dis[19];                                /* �O���̋������i�[����z��          */
	
	/* �^���t�@�C���̃f�[�^���i�[����z��Q*/
	int x[14];                                    /* �����̑�\�l���i�[����z��          */
	int fare[14];                                 /* �^�����i�[����z��                  */
	
	char josya[12+1];                             /* ��ԉw�����i�[����ϐ�              */
	char gesya[12+1];                             /* ���ԉw�����i�[����ϐ�              */
	
	float jdis;                                   /* ��ԉw�̋���                        */
	float gdis;                                   /* ���ԉw�̋���                        */
	float d;                                      /* ��ԉw���牺�ԉw�܂ł̍ŒZ����      */
	int dint;
	int key;                                      /* �t�@�C��"fare.dat"�����L�[          */
	
	int i;                                        /* ���[�v�J�E���^                      */
	
	FILE* fp1;                                    /* �t�@�C��"dist.dat"�̃t�@�C���|�C���^*/
	FILE* fp2;                                    /* �t�@�C��"fare.dat"�̃t�@�C���|�C���^*/
	
	/* �t�@�C���I�[�v�� */
	if((fp1=fopen(F_NAME1, "r"))==NULL)
	{
		printf("�t�@�C��dist.dat���J���܂���B\n");
		exit(1);
	}
	
	/* �t�@�C���I�[�v�� */
	if((fp2=fopen(F_NAME2, "r"))==NULL)
	{
		printf("�t�@�C��fare.dat���J���܂���B\n");
		exit(1);
	}
	
	/* dist.dat��ǂݍ��� */
	i=0;
	while((fscanf(fp1, "%s%4f%*c",&sta[i][0] , &dis[i]))!=EOF)
	{
		i++;
	}
	
	/* fare.dat��ǂݍ��� */
	i=0;
	while((fscanf(fp2, "%2d%4d%*c", &x[i], &fare[i]))!=EOF)
	{
		i++;	
	}
	
	/* �又�����[�v */
	while(1)
	{
		/* ��ԉw������� */
		printf("��ԉw������(END���͏I��)");
		scanf("%s", josya);
		if(strcmp(josya, "END")==0)
		{
			break;
		}
		
		/* ���ԉw������� */
		printf("���ԉw������");
		scanf("%s", gesya);
		
		/* dist.dat�����ԉw���̋��������� */
		for(i=0; i<19; i++)
		{
			if(strcmp(josya, sta[i])==0)
			{
				break;
			}
		}
		jdis=dis[i];
		
		/* dist.dat���牺�ԉw���̋��������� */
		for(i=0; i<19; i++)
		{
			if(strcmp(gesya, sta[i])==0)
			{
				break;
			}
		}
		gdis=dis[i];
		
		/* �����ƊO�����r���ď������ق���d�ɑ�� */
		if(jdis>gdis)
		{
			if( (21.7-(jdis-gdis)) < (jdis-gdis) )
			{
				d=21.7-(jdis-gdis);
			}
			else
			{
				d=jdis-gdis;
			}
		}
		else
		{
			if( (21.7-(gdis-jdis)) < (gdis-jdis) )
			{
				d=21.7-(gdis-jdis);
			}
			else
			{
				d=gdis-jdis;
			}
		}
		
		/* fare.dat�̃L�[�l�Ɣ�r����key�̒l�����肷�鏈�� */
		dint=(int)d;                                                       /* d�̐������݂̂�dint�ɑ������ */
		if(dint<=40)
		{
			if(dint<=20)
			{
				if(dint<=10)
				{
					if(0<=dint&&dint<=3)
					{
						key=3;
					}
					else if(3<dint&&dint<=6)
					{
						key=6;
					}
					else
					{
						key=10;
					}
				}
				else
				{
					if(10<dint&&dint<=15)
					{
						key=15;
					}
					else
					{
						key=20;
					}
				}
			}
		
			else
			{
				if(dint<=30)
				{
					if(20<dint&&dint<=25)
					{
						key=25;
					}
					else
					{
						key=30;
					}
				}
				else
				{
					if(30<dint&&dint<=35)
					{
						key=35;
					}
					else
					{
						key=40;
					}
				}
			}
		}
		else
		{
			if(60<=dint)
			{
				if(40<dint&&dint<=45)
				{
					key=45;
				}
				else if(45<dint&&dint<=50)
				{
					key=50;
				}
				else
				{
					key=60;
				}
			}
			else
			{
				if(60<dint&&dint<=70)
				{
					key=70;
				}
				else
				{
					key=80;
				}
			}
		}
	
		/* key�̒l��fare.dat�̃L�[�l���r���ĉ^�������� */
		for(i=0; i<14; i++)
		{
			if(key==x[i])
			{
				break;
			}
		}
		
		printf("������%3.1f\n", d);
		printf("�^����%d\n", fare[i]);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}