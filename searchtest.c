#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int numelicCheck(char inpdata[],int inpLength);                  /* 入力された数値をチェックする*/                                                          /* 完成*/
void printLine(void);                                                /* ライン表示*/                                                                            /* 未完成*/
void printBookHead(void);                                            /* ブックヘッダーを表示*/                                                                  /* 未完成*/
void printBookData(BOOK* book);                                   /* ブックデータを表示*/                                                                    /* 未完成*/

BOOK_MANAGER* initBookList(void);
int createBookList(BOOK_MANAFER* root, const char* fileName);
int registBookList(BOOK_MANAGER* root, const BOOK* bookData);

int LSearch(BOOK_MANAGER *root);                                 /* 図書データ検索メニュー*/
void inputBookCode(BOOK_MANAGER *root);                          /* 図書コードで検索し該当データを表示 searchBookを使う*/                                   /* 未完成*/
BOOK_MANAGER *searchBook(BOOK_MANAGER *root, int bookCode);      /* 図書データとコードを比較し、一致するデータへのポインタを返す*/                          /* 未完成*/
void inputAuthor(BOOK_MANAGER *root);                            /* 文字を入力し、それを著者名に含む図書データを全て表示 searchAuthorを使う*/               /* 未完成*/
void searchAuthor(BOOK_MANAGER *root, char authorCode[64]);      /* 入力された文字と図書データの著者名を比較し、文字を含むデータを全て表示*/                /* 未完成*/



int main(void)
{
	int chk_num; /* switch文の条件分に利用、numelicCheck()の返り値を格納 */
	char inp_code[256];	// 入力データを格納する
	
	BOOK_MANAGER* root = NULL;/* 図書データ（リスト構造）の先頭ノードへのポインタ */
	char* fileName = "library.bin";
	
	/* 図書データ構築 */
	root = initBookList();
	createBookList(root, fileName);
	
	/* メインメニューのループ*/
	while (1) {
		// clear_screen();
		/* コマンドインタプリタの画面クリア命令を実行＞メインメニューに戻るたびに実行する（仮置き） */

		/* メニュー表示 */
		printf("*** メインメニュー ***\n");
		printf(" 1：図書表\示\n");
		printf(" 2：図書検索\n");
		printf(" 3：貸し出し/削除\n");
		printf(" 4：貸出履歴表\示\n");
		printf(" 9：終了\n");

		scanf("%s", inp_code);
		chk_num = numelicCheck(inp_code, 1); 

		/* 各処理（機能ユニット）を実行 */
		switch (chk_num) {
			case 1: /* 1 表示 */
				// ret_num = LDisp(BOOK_MANAGER *root); // display.c 返り値0
				break;
			case 2: /* 2 検索 */
				// ret_num = LSearch(BOOK_MANAGER *root); // search.c 返り値0
				LSearch(BOOK_MANAGER* root);
				break;
			case 3: /* 3 貸し出し状況表示 */
				// ret_num = LRentRet(BOOK_MANAGER *root); // rentret.c 返り値0
				break;
			case 9: /* 9 終了処理 */
				// ret_num = endCheck(BOOK_MANAGER *root); // main.c 返り値 1 or 9
				break;
			default:
				break;
		}
		if(chk_num == 9) break; 
		// clear_screen(); /* コマンドインタプリタの画面クリア命令を実行（仮置き） */
	}
	return 0;
}


/* 以降が、追加ソースコードにあった、リストの初期化などを行う関数群*/
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
		printf("ファイルをオープンできません。%s\n", fileName);
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


/* 以降が検索を行う関数群*/
int LSearch(BOOK_MANAGER *root)
{
	char num[64];
	int skbn;
	
	while(1)
	{
		/* メニュー表示 */
		printf("*** 図書貸し出し/返却メニュー ***\n");
		printf("1 : 図書貸し出し\n");
		printf("2 : 図書返却\n");
		printf("9 : 戻る\n");
		printf("メニュー番号:");
		scanf("%s", num);
	
		/* 入力値チェック */
		skbn=numelicCheck(num, 1)		//common.c_numelicCheck関数呼び出し
	
	
		switch(skbn)
		{
			/* 図書コード検索 */
			//search.c_inputBookCode関数呼び出し
			case 1:
				inputBookCode(root);
				break;

			/* 著作名検索 */
			//search.c_inputAuthor関数呼び出し
			case 2:
				inputAuthor(root);	
				break;			
		
			/* メインメニューに戻る*/
			case 9:
				break;
			
			default:
				printf("エラーメッセージを入力する必要あり\n");
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
 * 名称		: 著者名検索処理
 * 処理		: 著者名あいまい検索文字列を入力し、
 *			: 該当する図書情報を検索した結果を全て表示する
 * 呼出形式	: void inputAuthor(BOOK_MANAGER *root)
 * 引数		: root		図書データ（リスト構造）の先頭ノードへのポインタ
 * 戻り値	: none
 */
void inputAuthor(BOOK_MANAGER *root)
{
	char authorCode[64]; 
	/* 著者名あいまい検索文字入力 */			//自作
	
	printf("著者名に含まれる文字を入力してください。\n");
	scanf("%s", authorCode);
	
	/* 図書データ検索 */
	//search.c_searchAuthor関数呼び出し
	searchAuthor(root, authorCode);

}

/*
 * 名称		: 図書コード検索処理
 * 処理		: 図書コードを入力し、該当する図書情報を検索した結果を全て表示する
 * 呼出形式	: void inputBookCode(BOOK_MANAGER *root)
 * 引数		: root		図書データ（リスト構造）の先頭ノードへのポインタ
 * 戻り値	: non
 */
void inputBookCode(BOOK_MANAGER *root)
{
	char bc[64];
	int bookCode;
	BOOK_MANAGER temp;
	
	/* 図書コード入力 */							//自作
	scanf("%s", bc);

	/* 入力値チェック */
	bookCode=numelicCheck(bc, 7);		//common.c_numelicCheck関数呼び出し
	
	/* 図書データ検索 */
	//search.c_searchBook関数呼び出し
	temp=searchBook(root, bookCode);

	/* 図書データヘッダー表示 */
	printBookHead(); //common.c_printBookHead関数呼び出し
	
	/* ライン表示 */
	printLine();		//common.c_printLine関数呼び出し
	
	/* 図書データ表示 */	
	//common.c_printBookData関数呼び出し
	printBookData(temp->bookData);
}

/*
 * 名称		: 図書データ検索処理
 * 処理		: 著者名あいまい検索文字列に該当する図書データを検索し、
 *			: 該当する図書データを全て表示する
 * 呼出形式	: BOOK_MANAGER *searchAuthor(BOOK_MANAGER *root, char authorCode[64])
 * 引数		: root		図書データ（リスト構造）の先頭ノードへのポインタ
 *			: authorCode	著者名あいまい検索文字列
 * 戻り値	: 見つかった図書管理データへのポインタ
 */
void searchAuthor(BOOK_MANAGER *root, char authorCode[64])
{
	/* 入力した文字が図書データの著者名に含まれるかチェックする	*/		//自作
	BOOK_MANAGER* temp=root->next;
	
	while(temp != NULL)
	{
		if(strstr(authorCode, temp->author)!=NULL)
		{
			/* 図書データヘッダー表示 */
			//common.c_printBookHead関数呼び出し
			printBookHead();

			/* ライン表示 */
			//common.c_printLine関数呼び出し
			printLine();

			/* 図書データ表示 */
			//common.c_printBookData関数呼び出し
			printBookData(temp->bookData);
		}
		
		temp = temp->next;
		
	}
	
}

/*
 * 名称		: 図書データ検索処理
 * 処理		: 図書コードに一致する図書データを検索し、一致した図書データへの
 * 			: ポインタを返す
 * 呼出形式	: BOOK_MANAGER *searchBook(BOOK_MANAGER *root, int bookCode)
 * 引数		: root		図書データ（リスト構造）の先頭ノードへのポインタ
 *			: bookCode	検索対象の図書コード（区分＋コード:7桁）
 * 戻り値	: 見つかった図書データへのポインタ
 *          : 見つからなかった場合は、NULL
 */
BOOK_MANAGER *searchBook(BOOK_MANAGER *root, int bookCode)
{
	/* 検索対象の図書コードと一致する図書データを検索 */
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
	

	/* 一致する場合、図書データのポインタを戻り値に設定 */
	
	/* 一致する図書データがなかった場合、*/
	/* 最終図書データの次ノードへのポインタ(NULL)を戻り値に設定 */
	
}

