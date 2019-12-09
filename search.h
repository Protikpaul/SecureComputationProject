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
void output( int Num, int bound)
{
	if(Num==5)
	{
		int NumOfParties=5, UpperBound=bound;
		printf("Enter the number of parties:\t 5\n");
		//scanf("%d",&NumOfParties);
		//----------------------------------------------------------------------------------------
		int WtVecEval[NumOfParties+1], WtVecGen[NumOfParties+1];
		WtVecEval[0]=0; WtVecEval[1]=0; WtVecEval[2]=0; WtVecEval[3]=0; WtVecEval[4]=0; WtVecEval[5]=0;
		WtVecGen[0]=0; WtVecGen[1]=0; WtVecGen[2]=1; WtVecGen[3]=1; WtVecGen[4]=1; WtVecGen[5]=1;
		//----------------------------------------------------------------------------------------
		int IfHonest[NumOfParties+1];
		init(IfHonest,NumOfParties);
		//print(IfHonest,NumOfParties);
		int flag=0;
		int len;
		int a=pow(2, NumOfParties);
		for(int l1=0; l1<=UpperBound; l1++)
		for(int l2=0; l2<=UpperBound; l2++)
		for(int l3=0; l3<=UpperBound; l3++)
		for(int l4=0; l4<=UpperBound; l4++)
		for(int l5=0; l5<=UpperBound; l5++)
		for(int k1=0; k1<=UpperBound; k1++)
		for(int k2=0; k2<=UpperBound; k2++)
		for(int k3=0; k3<=UpperBound; k3++)
		for(int k4=0; k4<=UpperBound; k4++)
		for(int k5=0; k5<=UpperBound; k5++)
		{
			flag=0;
			WtVecEval[1]=k1; WtVecEval[2]=k2; WtVecEval[3]=k3; WtVecEval[4]=k4; WtVecEval[5]=k5;
			WtVecGen[1]=l1; WtVecGen[2]=k2; WtVecGen[3]=k3; WtVecGen[4]=k4; WtVecGen[5]=l5;
			printf("Check for Eval= {%d\t%d\t%d\t%d\t%d}\n", k1,k2,k3,k4,k5);
			printf("Check for Gen= {%d\t%d\t%d\t%d\t%d}\n", l1,l2,l3,l4,l5);
			if((k1==0 && k2==0 && k3==0 && k4==0 && k5==0)||(l1==0 && l2==0 && l3==0 && l4==0 && l5==0))
			//((k1==0 && k2==0 && k3==0 && k4==0)||(l1==0 && l2==0 && l3==0 && l4==0))
				break;
			else
			{
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
						> (sum over j=1 to NumOfParties (WtVecEval))/2*/
						/*check sum over j=1 to NumOfParties (WtVecGen[j].IfHonest[j])
						> (sum over j=1 to NumOfParties (WtVecGen))/2*/
						//------------------------------------------------------------------------
						int CheckEval=0, CheckGen=0;
						bool EvalSecure, GenSecure;
						//print(IfHonest,NumOfParties);
						for(int j=1; j<=NumOfParties; j++)
						{
							CheckEval = CheckEval + IfHonest[j] * WtVecEval[j];
							CheckGen = CheckGen + IfHonest[j] * WtVecGen[j];
							//printf("CheckEval = %d\t CheckGen = %d\n", CheckEval, CheckGen);
						}
						//printf("CheckEval = %d\t CheckGen = %d\n", CheckEval, CheckGen);
						//------------------------------------------------------------------------
						if(CheckEval > ((float)sum(WtVecEval, NumOfParties)/2))
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
						if(CheckGen > ((float)sum(WtVecGen, NumOfParties)/2))
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
					printf("\tsecure for Eval={%d,\t%d,\t%d,\t%d\t%d}\n",k1,k2,k3,k4,k5);
					//printf("\tsecure for Eval={%d,\t%d,\t%d,\t%d}\n",k1,k2,k3,k4);
					printf("\tsecure for Gen={%d,\t%d,\t%d,\t%d\t%d}\n",l1,l2,l3,l4,l5);
					//printf("\tsecure for Gen={%d,\t%d,\t%d,\t%d}\n",l1,l2,l3,l4);
					goto OUTSIDE5;
				}
			}	
		}
		OUTSIDE5:
		if(flag==0)
			printf ("outside\n");
	}
	else if(Num==4)
	{
		int NumOfParties=4, UpperBound=bound;
		printf("Enter the number of parties:\t 4\n");
		//scanf("%d",&NumOfParties);
		//----------------------------------------------------------------------------------------
		int WtVecEval[NumOfParties+1], WtVecGen[NumOfParties+1];
		WtVecEval[0]=0; WtVecEval[1]=0; WtVecEval[2]=0; WtVecEval[3]=0; WtVecEval[4]=0; //WtVecEval[5]=0;
		WtVecGen[0]=0; WtVecGen[1]=0; WtVecGen[2]=1; WtVecGen[3]=1; WtVecGen[4]=1; //WtVecGen[5]=1;
		//----------------------------------------------------------------------------------------
		int IfHonest[NumOfParties+1];
		init(IfHonest,NumOfParties);
		//print(IfHonest,NumOfParties);
		int flag=0;
		int len;
		int a=pow(2, NumOfParties);
		for(int l1=0; l1<=UpperBound; l1++)
		for(int l2=0; l2<=UpperBound; l2++)
		for(int l3=0; l3<=UpperBound; l3++)
		for(int l4=0; l4<=UpperBound; l4++)
		//for(int l5=0; l5<=UpperBound; l5++)
		for(int k1=0; k1<=UpperBound; k1++)
		for(int k2=0; k2<=UpperBound; k2++)
		for(int k3=0; k3<=UpperBound; k3++)
		for(int k4=0; k4<=UpperBound; k4++)
		//for(int k5=0; k5<=UpperBound; k5++)
		{
			flag=0;
			WtVecEval[1]=k1; WtVecEval[2]=k2; WtVecEval[3]=k3; WtVecEval[4]=k4; //WtVecEval[5]=k5;
			WtVecGen[1]=l1; WtVecGen[2]=k2; WtVecGen[3]=k3; WtVecGen[4]=k4; //WtVecGen[5]=l5;
			printf("Check for Eval= {%d\t%d\t%d\t%d}\n", k1,k2,k3,k4);
			printf("Check for Gen= {%d\t%d\t%d\t%d}\n", l1,l2,l3,l4);
			//if((k1==0 && k2==0 && k3==0 && k4==0 && k5==0)||(l1==0 && l2==0 && l3==0 && l4==0 && l5==0))
			if((k1==0 && k2==0 && k3==0 && k4==0)||(l1==0 && l2==0 && l3==0 && l4==0))
				break;
			else
			{
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
						> (sum over j=1 to NumOfParties (WtVecEval))/2*/
						/*check sum over j=1 to NumOfParties (WtVecGen[j].IfHonest[j])
						> (sum over j=1 to NumOfParties (WtVecGen))/2*/
						//------------------------------------------------------------------------
						int CheckEval=0, CheckGen=0;
						bool EvalSecure, GenSecure;
						//print(IfHonest,NumOfParties);
						for(int j=1; j<=NumOfParties; j++)
						{
							CheckEval = CheckEval + IfHonest[j] * WtVecEval[j];
							CheckGen = CheckGen + IfHonest[j] * WtVecGen[j];
							//printf("CheckEval = %d\t CheckGen = %d\n", CheckEval, CheckGen);
						}
						//printf("CheckEval = %d\t CheckGen = %d\n", CheckEval, CheckGen);
						//------------------------------------------------------------------------
						if(CheckEval > ((float)sum(WtVecEval, NumOfParties)/2))
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
						if(CheckGen > ((float)sum(WtVecGen, NumOfParties)/2))
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
					//printf("\tsecure for Eval={%d,\t%d,\t%d,\t%d\t%d}\n",k1,k2,k3,k4,k5);
					printf("\tsecure for Eval={%d,\t%d,\t%d,\t%d}\n",k1,k2,k3,k4);
					//printf("\tsecure for Gen={%d,\t%d,\t%d,\t%d\t%d}\n",l1,l2,l3,l4,l5);
					printf("\tsecure for Gen={%d,\t%d,\t%d,\t%d}\n",l1,l2,l3,l4);
					goto OUTSIDE4;
				}
			}	
		}
		OUTSIDE4:
		if(flag==0)
			printf ("outside\n");
	}
	
}