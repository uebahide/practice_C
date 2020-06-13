#include  "option9-1.h"

int main(void)
{
	int i;
	struct DATA data[MAX_CNT];
	
	i=in(data);
	sort(data, i);
	out(data, i);
	
	return 0;
}