//nQueens.cpp
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#define MAX 100
#define TRUE 1
#define FALSE 0


using namespace std;

int A[MAX], col[MAX],Diag[MAX],Diag_neg[MAX];
int n,dem=0;
//thiet lap ban dau
void Init()
{
	cout<<"Nhap phan tu n: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		col[i]=TRUE;
	}
	for(int i=1;i<=2*n-1;i++)
	{
		Diag[i]=Diag_neg[i]=TRUE;
	}

}

void Print()
{
	cout<<"Phuong an thu "<<++dem<<": ";
	for(int i=1;i<=n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Try(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(col[j]&&Diag[i-j+n]&&Diag_neg[i+j-1])
		{
			A[i]=j;
			col[j]=Diag[i-j+n]=Diag_neg[i+j-1]=FALSE;
			if(i==n)
			{
				Print();
			}
			else
			{
				Try(i+1);
			}
			col[j]=Diag[i-j+n]=Diag_neg[i+j-1]=TRUE;
		}

	}

}

int main()
{
	Init();
	Try(1);
	system("PAUSE");
	return 0;

}
