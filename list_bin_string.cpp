//list_bin_string.cpp
#include<iostream>
#include<stdlib.h>

using namespace std;
//setup
#define MAX 100
#define TRUE 1
#define FALSE 0
int n, X[MAX], count=0;

//func Init
void Init()
{
	cout<<"n= ";
	cin>>n;
}

//func Result
void Result()
{
	cout<<"Buoc "<<++count<<":";
	for(int i=1;i<=n;i++)
	{
		cout<<X[i]<<" ";
	}
	cout<<endl;
}

//func Try
void Try(int i)
{
	for(int j=0;j<=1;j++)//chuoi 0-1 nen j trong (0,1)
	{
		X[i]=j;
		if(i==n) Result();
		else Try(i+1);
	}
}


int main()
{
	Init();
	Try(1);
	system("PAUSE");
	return 0;
}
