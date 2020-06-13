

void sort(struct DATA* data, int n)
{
	int i, j;
	struct DATA work;
	
	for(i=0; i<n-1, i++)
	{
		for(j=i+1; j<n; j++)
		{
			if((data+i)->age < (data+j)->age)
			{
				work=*(data+i);
				*(data+i)=*(data+j);
				*(data+j)=work;
			}
		}
	}
}