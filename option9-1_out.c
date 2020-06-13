
void out(struct DATA* data, int n)
{
	int i;
	float attl=0;
	float httl=0;
	
	printf("名前           年齢    身長\n");
	for(i=0; i<n; i++)
	{
		printf("%s        %d     %5.1f\n", (data+i)->name, (data+i)->age, (data+i)->height);
		
		attl+=(data+i)->age;
		httl+=(data+i)->height;
	}
	
	printf("平均年齢＝%5.1f  平均身長＝%5.1f\n", attl/i, httl/i);
	printf("入力件数＝%d件\n", i);
}