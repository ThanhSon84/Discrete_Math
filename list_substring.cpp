//list_substring.cpp
#include<iostream>
#include<stdlib.h>

using namespace std;
//setup
#define MAX 100
#define TRUE 1
#define FALSE 0
int n,k, X[MAX], count=0;

//func Init
void Init()
{
	cout<<"n= ";
	cin>>n;
	cout <<"\nk= ";
	cin>>k;
	X[0]=0;//buoc nay quan trong

}

//func Result
void Result()
{
	cout<<"Buoc "<<++count<<":";
	for(int i=1;i<=k;i++)
	{
		cout<<X[i]<<" ";
	}
	cout<<endl;
}

//func Try
void Try(int i)
{
	for(int j=X[i-1]+1;j<=n-k+i;j++)//chuoi 0-1 nen j trong (0,1)
	{
		X[i]=j;
		if(i==k) Result();
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
