
void out(struct DATA* data, int n)
{
	int i;
	float attl=0;
	float httl=0;
	
	printf("���O           �N��    �g��\n");
	for(i=0; i<n; i++)
	{
		printf("%s        %d     %5.1f\n", (data+i)->name, (data+i)->age, (data+i)->height);
		
		attl+=(data+i)->age;
		httl+=(data+i)->height;
	}
	
	printf("���ϔN�%5.1f  ���ϐg����%5.1f\n", attl/i, httl/i);
	printf("���͌�����%d��\n", i);
}