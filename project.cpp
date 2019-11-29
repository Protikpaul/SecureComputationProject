#include<stdio.h>
#include<math.h>

//function to compute the sum of all the entries in an array
int sum(int a[],int n)
{
	int s=0;
	for(int i=1;i<=n;i++)
		s=s+a[i];
	return s;
}
//----------------------------------------------------------------------------

//function to convert decimal number to binary and storing in an array
void DecimalToBinary(int n, int a[], int len)
{
	int i=1;
	while(n>0)
	{
		a[i]=n%2;
		//printf("a[%d]=%d\n",i,a[i]);
		n=n/2;
		//printf("%d\n",n);
		i++;
	}
	//printf("\n");
	//for(int j=0; j<i; j++)
		//a[j]=b[i-1-j];
	//for(int j=1; j<=len; j++)
	//	printf("%d\t",a[j]);
	//printf("\n");
}
//----------------------------------------------------------------------------

//function to count the number of zeros in an array
int NumOfZeros(int a[], int n)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			count++;
	}
	return count;
}
//------------------------------------------------------------------------------------------------
int main()
{
	int NumOfParties=5, UpperBound=2;
	printf("Enter the number of parties:\t 5");
	//scanf("%d",&NumOfParties);
	//----------------------------------------------------------------------------------------
	int WtVecEval[NumOfParties+1], WtVecGen[NumOfParties+1];
	WtVecEval[0]=0; WtVecEval[1]=0; WtVecEval[2]=0; WtVecEval[3]=0; WtVecEval[4]=0; WtVecEval[5]=0;
	WtVecGen[0]=0; WtVecGen[1]=0; WtVecGen[2]=0; WtVecGen[3]=0; WtVecGen[4]=0; WtVecGen[5]=0;
	/*for(int i = 1; i <= NumOfParties; i++)
		{
			WtVecEval[i]=1;
			WtVecGen[i]=0;
		}
	/*
	printf("Do you want manual inputs for weight values of Eval and Gen?(1/0):\n");
	int ans;
	scanf(" %d",&ans);
	if(ans==1)
	{
		printf("Enter weight values of Eval and Gen:\n");
		for(int i=1; i<=NumOfParties; i++)
			scanf("%d%d",&WtVecEval[i],&WtVecGen[i]);
	}
	else if(ans==0)
	{
		for(int i = 1; i <= NumOfParties; i++)
		{
			WtVecEval[i]=1;
			WtVecGen[i]=0;
		}
	}*/
	//----------------------------------------------------------------------------------------
	int IfHonest[NumOfParties+1];
	
	int a=pow(2, NumOfParties);
	for(int k1=1; k1<=UpperBound; k1++)
	for(int k2=1; k2<=UpperBound; k2++)
	for(int k3=1; k3<=UpperBound; k3++)
	for(int k4=1; k4<=UpperBound; k4++)
	for(int k5=1; k5<=UpperBound; k5++)
	{
		WtVecEval[1]=k1; WtVecEval[2]=k2; WtVecEval[3]=k3; WtVecEval[4]=k4; WtVecEval[5]=k5;
		for(int i=0; i<a; i++)
		{
			DecimalToBinary(i,IfHonest,NumOfParties);
		//----------------------------------------------------------------------------------------
			/* A party either an honest party or corrupt
			if_honest[i]=0, then ith party is corrupt*/
		//----------------------------------------------------------------------------------------
			/*no check is required if number of corrupt parties is more than NumOfParties-2*/
		//----------------------------------------------------------------------------------------
			if(NumOfZeros(IfHonest, NumOfParties)<(NumOfParties-1))
			{
				//------------------------------------------------------------------------	
				/*check sum over j=1 to NumOfParties (WtVecEval[j].IfHonest[j])
			 	>= (sum over j=1 to NumOfParties (WtVecEval))/2*/
				//------------------------------------------------------------------------
				int CheckEval=0, CheckGen=0;
				bool EvalSecure, GenSecure;
				for(int j=1; j<=NumOfParties; j++)
				{
					CheckEval = CheckEval + IfHonest[j] * WtVecEval[j];
					CheckGen = CheckGen + IfHonest[j] * WtVecGen[j];
				}
				if(CheckEval > floor(sum(WtVecEval, NumOfParties)/2))
				{
					printf("||\tEval is secure for %d\t ||",i);
					EvalSecure=true;
				}
				else 
				{
					printf("\tEval is not secure for %d\t ||",i);
					GenSecure=false;
				}
				if(CheckGen > floor(sum(WtVecGen, NumOfParties)/2))
				{
					printf("\tGen is secure for %d\t ||",i);
					GenSecure=true;
				}
				else
				{
					printf("\tGen is not secure for %d\t ||",i);
					GenSecure=false;
				}
				printf("\n");
				if(EvalSecure || GenSecure)
					printf("\t\t||Secure||\t\t\n");
				else
				{	
					printf("\t\t||Not Secure||\n");
					break;
				}
			}
	 
		}
	}
}
