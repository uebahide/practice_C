#include<stdio.h>

char* rtn_season(char (*str)[7], int month);

int main(void)
{
	char seasons[][7]={"WINTER","SPRING","SUMMER","AUTUMN"};
	int month;
	char *season;
	
	printf("Œ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢„");
	scanf("%d", &month);
	
	season=rtn_season(seasons, month);
	printf("‹Gß‚Í¡%s‚Å‚·\n", season);
	return 0;
}

char* rtn_season(char (*str)[7], int month)
{
	char *rtn_str;
	
	switch(month)
	{
		case 1:
			rtn_str=*str;
			break;
		case 2:
			rtn_str=*str;
			break;
		case 3:
			rtn_str=*(str+1);
			break;
		case 4:
			rtn_str=*(str+1);
			break;
		case 5:
			rtn_str=*(str+1);
			break;
		case 6:
			rtn_str=*(str+2);
			break;
		case 7:
			rtn_str=*(str+2);
			break;
		case 8:
			rtn_str=*(str+2);
			break;
		case 9:
			rtn_str=*(str+3);
			break;
		case 10:
			rtn_str=*(str+3);
			break;
		case 11:
			rtn_str=*(str+3);
			break;
		case 12:
			rtn_str=*str;
			break;
		default:
			return NULL;
	}
	
	printf("%s\n", str);
	printf("%s\n", *str);
	
	return (rtn_str);
}