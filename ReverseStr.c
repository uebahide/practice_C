#include<stdio.h>
#include<string.h>

void reverseStr(char *str);

int main(void)
{
	char str[100];                             /* �Ώە�����̗̈�*/
	
	printf("���͕����񁁁�");                
	scanf("%s", str);                          /* ������W������  */
	
	reverseStr(str);                           /* ���בւ�����    */
	
	printf("����ւ��ぁ��%s\n", str);
	
	return 0;
}

void reverseStr(char *str)
{
	int i;                                     /* ���[�v�J�E���^  */
	int length;                                /* ������̃T�C�Y  */
	char work;                                 /* �ޔ�p�ϐ�      */
	
	length=strlen(str);                        /* ������̃T�C�Y���� */
	
	for(i=0; i<length/2; i++)                  /* ����ւ�����    */
	{
		work=*(str+i);
		*(str+i)=*(str+(length-i-1));
		*(str+(length-i-1))=work;
	}
}