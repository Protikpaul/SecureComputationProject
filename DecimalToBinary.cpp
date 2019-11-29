#include<stdio.h>

int DecimalToBinary(int num, int bin[])
{
	int i=1;
	while(num>0)
	{
		bin[i]=num%2;
		num=num/2;
		i++;
	}
	return i;
}

int main()
{
	int num;
	scanf("%d",&num);
	int bin[32];
	int i=DecimalToBinary(num, bin);
	for(int j=1; j<i; j++)
		printf("%d\t",bin[j]);

	printf("\n");
}	
