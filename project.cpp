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
int DecimalToBinary(int num, int bin[], int len)
{
	int i=1;
	while(num>0)
	{
		bin[i]=num%2;
		num=num/2;
		i++;
	}
	/*for(int j=1; j<i; j++)
		printf("%d\t",bin[j]);

	printf("\n");*/
	return i;
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

//function to print an array
void print(int a[], int n)
{
	for(int i=1; i<=n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
//------------------------------------------------------------------------------------------------
//function to initialize an array
void init(int a[], int n)
{
	for(int i=0; i<=n; i++)
		a[i]=0;
}
//------------------------------------------------------------------------------------------------
int main()
{
	int NumOfParties=5, UpperBound=2;
	printf("Enter the number of parties:\t 5\n");
	//scanf("%d",&NumOfParties);
	//----------------------------------------------------------------------------------------
	int WtVecEval[NumOfParties+1], WtVecGen[NumOfParties+1];
	WtVecEval[0]=0; WtVecEval[1]=0; WtVecEval[2]=0; WtVecEval[3]=0; WtVecEval[4]=0; WtVecEval[5]=0;
	WtVecGen[0]=0; WtVecGen[1]=1; WtVecGen[2]=1; WtVecGen[3]=1; WtVecGen[4]=1; WtVecGen[5]=1;
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
	init(IfHonest,NumOfParties);
	//print(IfHonest,NumOfParties);
	int flag=0;
	int len;
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
			init(IfHonest,NumOfParties);
			len = DecimalToBinary(i,IfHonest,NumOfParties);
			//print(IfHonest,NumOfParties);
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
				//------------------------------------------------------------------------
				if(CheckEval >= ceil((float)sum(WtVecEval, NumOfParties)/2))
				{
					printf("||\tEval is secure for %d\t ||",i);
					EvalSecure=true;
				}
				else 
				{
					EvalSecure=false;
					printf("\tEval is not secure for %d\t ||",i);
				}
				//-------------------------------------------------------------------------
				if(CheckGen >= ceil((float)sum(WtVecGen, NumOfParties)/2))
				{
					printf("\tGen is secure for %d\t ||",i);
					GenSecure=true;
				}
				else
				{
					GenSecure=false;
					printf("\tGen is not secure for %d\t ||",i);
				}
				//-------------------------------------------------------------------------
				printf("\n");
				if(EvalSecure == false && GenSecure == false) printf("--------------NOT SECURE------------\n");
				if(EvalSecure || GenSecure)
					printf("\t\t||Secure||\t\t\n");
				else
				{	
					printf("\t\t||Not Secure||\n");
					flag=1;
					break;
				}
			}
	 
		}
		if(flag==0)
		{
			printf("\tsecure if for Eval={%d,\t%d,\t%d,\t%d,\t%d}\n",k1,k2,k3,k4,k5);
			goto OUTSIDE;
		}
	}
	OUTSIDE:
	printf ("outside\n");
}
