#include<stdio.h>
#include<math.h>
#include "search.h"

int main()
{
	int NumOfParties, bound;
	printf("Enter the number of parties:\n");
	scanf("%d",&NumOfParties);
	printf("Enter the upper bound to execute the search:\n");
	scanf("%d",&bound);
	output(NumOfParties, bound);
}