#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int numelicCheck(char inpdata[],int inpLength);                  /* ���͂��ꂽ���l���`�F�b�N����*/                                                          /* ����*/
void printLine(void);                                                /* ���C���\��*/                                                                            /* ������*/
void printBookHead(void);                                            /* �u�b�N�w�b�_�[��\��*/                                                                  /* ������*/
void printBookData(BOOK* book);                                   /* �u�b�N�f�[�^��\��*/                                                                    /* ������*/

BOOK_MANAGER* initBookList(void);
int createBookList(BOOK_MANAFER* root, const char* fileName);
int registBookList(BOOK_MANAGER* root, const BOOK* bookData);

int LSearch(BOOK_MANAGER *root);                                 /* �}���f�[�^�������j���[*/
void inputBookCode(BOOK_MANAGER *root);                          /* �}���R�[�h�Ō������Y���f�[�^��\�� searchBook���g��*/                                   /* ������*/
BOOK_MANAGER *searchBook(BOOK_MANAGER *root, int bookCode);      /* �}���f�[�^�ƃR�[�h���r���A��v����f�[�^�ւ̃|�C���^��Ԃ�*/                          /* ������*/
void inputAuthor(BOOK_MANAGER *root);                            /* ��������͂��A����𒘎Җ��Ɋ܂ސ}���f�[�^��S�ĕ\�� searchAuthor���g��*/               /* ������*/
void searchAuthor(BOOK_MANAGER *root, char authorCode[64]);      /* ���͂��ꂽ�����Ɛ}���f�[�^�̒��Җ����r���A�������܂ރf�[�^��S�ĕ\��*/                /* ������*/



int main(void)
{
	int chk_num; /* switch���̏������ɗ��p�AnumelicCheck()�̕Ԃ�l���i�[ */
	char inp_code[256];	// ���̓f�[�^���i�[����
	
	BOOK_MANAGER* root = NULL;/* �}���f�[�^�i���X�g�\���j�̐擪�m�[�h�ւ̃|�C���^ */
	char* fileName = "library.bin";
	
	/* �}���f�[�^�\�z */
	root = initBookList();
	createBookList(root, fileName);
	
	/* ���C�����j���[�̃��[�v*/
	while (1) {
		// clear_screen();
		/* �R�}���h�C���^�v���^�̉�ʃN���A���߂����s�����C�����j���[�ɖ߂邽�тɎ��s����i���u���j */

		/* ���j���[�\�� */
		printf("*** ���C�����j���[ ***\n");
		printf(" 1�F�}���\\��\n");
		printf(" 2�F�}������\n");
		printf(" 3�F�݂��o��/�폜\n");
		printf(" 4�F�ݏo����\\��\n");
		printf(" 9�F�I��\n");

		scanf("%s", inp_code);
		chk_num = numelicCheck(inp_code, 1); 

		/* �e�����i�@�\���j�b�g�j�����s */
		switch (chk_num) {
			case 1: /* 1 �\�� */
				// ret_num = LDisp(BOOK_MANAGER *root); // display.c �Ԃ�l0
				break;
			case 2: /* 2 ���� */
				// ret_num = LSearch(BOOK_MANAGER *root); // search.c �Ԃ�l0
				LSearch(BOOK_MANAGER* root);
				break;
			case 3: /* 3 �݂��o���󋵕\�� */
				// ret_num = LRentRet(BOOK_MANAGER *root); // rentret.c �Ԃ�l0
				break;
			case 9: /* 9 �I������ */
				// ret_num = endCheck(BOOK_MANAGER *root); // main.c �Ԃ�l 1 or 9
				break;
			default:
				break;
		}
		if(chk_num == 9) break; 
		// clear_screen(); /* �R�}���h�C���^�v���^�̉�ʃN���A���߂����s�i���u���j */
	}
	return 0;
}


/* �ȍ~���A�ǉ��\�[�X�R�[�h�ɂ������A���X�g�̏������Ȃǂ��s���֐��Q*/
BOOK_MANAGER* initBookList(void)
{
	BOOK_MANAGER* dummy;
	
	dummy = (BOOK_MANAGER*)malloc(sizeof(BOOK_MANAGER));
	
	dummy->book.bookKbn = 0;
	dummy->book.bookCode = 0;
	dummy->book.title[0] = '\0';
	dummy->book.author[0] = '\0';
	dummy->book.isRent = 0;
	dummy->next = NULL;
	
	return dummy;
}

int createBookList(BOOK_MANAFER* root, const char* fileName)
{
	FILE* fp;
	int ret=1;
	BOOK bookData;
	
	if((fp=fopen(fileName, "rb"))==NULL)
	{
		printf("�t�@�C�����I�[�v���ł��܂���B%s\n", fileName);
	}
	else
	{
		while(fread(&bookData, sizeof(BOOK), 1, fp) != 0)
		{
			registBookList(root, &bookData);
		}
		
		fclose(fp);
		ret=0;
	}
	
	return ret;
}

int registBookList(BOOK_MANAGER* root, const BOOK* bookData)
{
	BOOK_MANAGER* temp=root;
	BOOK_MANAGER* new;
	int ret = 1;
	
	new=(BOOK_MANAGER*)malloc(sizeof(BOOK_MANAGER));
	
	if (new != NULL) 
	{
		new->bookData = *bookData;
		new->next = root->next;
		root->next=new;
		
		ret = 0;
	}
	
	return ret;
}


/* �ȍ~���������s���֐��Q*/
int LSearch(BOOK_MANAGER *root)
{
	char num[64];
	int skbn;
	
	while(1)
	{
		/* ���j���[�\�� */
		printf("*** �}���݂��o��/�ԋp���j���[ ***\n");
		printf("1 : �}���݂��o��\n");
		printf("2 : �}���ԋp\n");
		printf("9 : �߂�\n");
		printf("���j���[�ԍ�:");
		scanf("%s", num);
	
		/* ���͒l�`�F�b�N */
		skbn=numelicCheck(num, 1)		//common.c_numelicCheck�֐��Ăяo��
	
	
		switch(skbn)
		{
			/* �}���R�[�h���� */
			//search.c_inputBookCode�֐��Ăяo��
			case 1:
				inputBookCode(root);
				break;

			/* ���얼���� */
			//search.c_inputAuthor�֐��Ăяo��
			case 2:
				inputAuthor(root);	
				break;			
		
			/* ���C�����j���[�ɖ߂�*/
			case 9:
				break;
			
			default:
				printf("�G���[���b�Z�[�W����͂���K�v����\n");
				break;
		}
		
		if(skbn==9)
		{
			break;	
		}
	}
	return 0;
}

/*
 * ����		: ���Җ���������
 * ����		: ���Җ������܂��������������͂��A
 *			: �Y������}�����������������ʂ�S�ĕ\������
 * �ďo�`��	: void inputAuthor(BOOK_MANAGER *root)
 * ����		: root		�}���f�[�^�i���X�g�\���j�̐擪�m�[�h�ւ̃|�C���^
 * �߂�l	: none
 */
void inputAuthor(BOOK_MANAGER *root)
{
	char authorCode[64]; 
	/* ���Җ������܂������������� */			//����
	
	printf("���Җ��Ɋ܂܂�镶������͂��Ă��������B\n");
	scanf("%s", authorCode);
	
	/* �}���f�[�^���� */
	//search.c_searchAuthor�֐��Ăяo��
	searchAuthor(root, authorCode);

}

/*
 * ����		: �}���R�[�h��������
 * ����		: �}���R�[�h����͂��A�Y������}�����������������ʂ�S�ĕ\������
 * �ďo�`��	: void inputBookCode(BOOK_MANAGER *root)
 * ����		: root		�}���f�[�^�i���X�g�\���j�̐擪�m�[�h�ւ̃|�C���^
 * �߂�l	: non
 */
void inputBookCode(BOOK_MANAGER *root)
{
	char bc[64];
	int bookCode;
	BOOK_MANAGER temp;
	
	/* �}���R�[�h���� */							//����
	scanf("%s", bc);

	/* ���͒l�`�F�b�N */
	bookCode=numelicCheck(bc, 7);		//common.c_numelicCheck�֐��Ăяo��
	
	/* �}���f�[�^���� */
	//search.c_searchBook�֐��Ăяo��
	temp=searchBook(root, bookCode);

	/* �}���f�[�^�w�b�_�[�\�� */
	printBookHead(); //common.c_printBookHead�֐��Ăяo��
	
	/* ���C���\�� */
	printLine();		//common.c_printLine�֐��Ăяo��
	
	/* �}���f�[�^�\�� */	
	//common.c_printBookData�֐��Ăяo��
	printBookData(temp->bookData);
}

/*
 * ����		: �}���f�[�^��������
 * ����		: ���Җ������܂�����������ɊY������}���f�[�^���������A
 *			: �Y������}���f�[�^��S�ĕ\������
 * �ďo�`��	: BOOK_MANAGER *searchAuthor(BOOK_MANAGER *root, char authorCode[64])
 * ����		: root		�}���f�[�^�i���X�g�\���j�̐擪�m�[�h�ւ̃|�C���^
 *			: authorCode	���Җ������܂�����������
 * �߂�l	: ���������}���Ǘ��f�[�^�ւ̃|�C���^
 */
void searchAuthor(BOOK_MANAGER *root, char authorCode[64])
{
	/* ���͂����������}���f�[�^�̒��Җ��Ɋ܂܂�邩�`�F�b�N����	*/		//����
	BOOK_MANAGER* temp=root->next;
	
	while(temp != NULL)
	{
		if(strstr(authorCode, temp->author)!=NULL)
		{
			/* �}���f�[�^�w�b�_�[�\�� */
			//common.c_printBookHead�֐��Ăяo��
			printBookHead();

			/* ���C���\�� */
			//common.c_printLine�֐��Ăяo��
			printLine();

			/* �}���f�[�^�\�� */
			//common.c_printBookData�֐��Ăяo��
			printBookData(temp->bookData);
		}
		
		temp = temp->next;
		
	}
	
}

/*
 * ����		: �}���f�[�^��������
 * ����		: �}���R�[�h�Ɉ�v����}���f�[�^���������A��v�����}���f�[�^�ւ�
 * 			: �|�C���^��Ԃ�
 * �ďo�`��	: BOOK_MANAGER *searchBook(BOOK_MANAGER *root, int bookCode)
 * ����		: root		�}���f�[�^�i���X�g�\���j�̐擪�m�[�h�ւ̃|�C���^
 *			: bookCode	�����Ώۂ̐}���R�[�h�i�敪�{�R�[�h:7���j
 * �߂�l	: ���������}���f�[�^�ւ̃|�C���^
 *          : ������Ȃ������ꍇ�́ANULL
 */
BOOK_MANAGER *searchBook(BOOK_MANAGER *root, int bookCode)
{
	/* �����Ώۂ̐}���R�[�h�ƈ�v����}���f�[�^������ */
	BOOK_MANAGER* temp = root->next;
	int tempBookCode;
	
	while(temp!=NULL)
	{
		tempBookCode=(temp->bookKbn*100000) + (temp->bookCode);
		
		if(tempBookCode==bookCode)
		{
			break;	
		}
		
		temp=temp->next;
	}
	
	return temp;
	

	/* ��v����ꍇ�A�}���f�[�^�̃|�C���^��߂�l�ɐݒ� */
	
	/* ��v����}���f�[�^���Ȃ������ꍇ�A*/
	/* �ŏI�}���f�[�^�̎��m�[�h�ւ̃|�C���^(NULL)��߂�l�ɐݒ� */
	
}

