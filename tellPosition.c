#include<stdio.h>
#include<string.h>

char* tellPosition(char* str, char c);
 
int main(void)
{
	char str[100];
	char c;
	char *p;
	
	printf("�����Ώە����񁁁�");
	gets(str);                                                      /* �����Ώە��������� */
	
	printf("�������镶������");
	scanf("%c", &c);                                                /* �������镶�����ɂイ��傭*/
	
	p=tellPosition(str, c);                                         /* �������� */
	
	/* ���ʕ�������o�� */
	if(p!=NULL)
	{
		printf("��v�����ȍ~����%s\n", p);
	}
	
	else
	{
		printf("��v�����ȍ~�����������镶���ƈ�v���܂���\n");
	}
	
	return 0;
} 

char* tellPosition(char* str, char c)
{
	int i;                                                           /* ���[�v�J�E���^ */
	int length;                                                      /* ������̃T�C�Y */
	char* p=NULL;                                                   
	
	length=strlen(str);
	
	/* �������� */
	for(i=0; i<length; i++)
	{
		if(*(str+i)==c)
		{
			p=str+i;
			break;
		}
	}
	
	return p;
}