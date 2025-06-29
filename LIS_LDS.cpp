//LIS_LDS.cpp
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//nhap file
	ifstream Input("tapcon.in");
	int n;

	Input>>n;

	vector<int> a(n);

	for(int i=0;i<n;i++)
	{
		Input>>a[i];
	}

	Input.close();

	//tao LIS

	vector<int> dp_inc(n,1);
	vector<int> dp_prev_inc(n,-1);

	int max_len_inc=0;
	int end_idx_inc=-1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j]&&dp_inc[i]<dp_inc[j]+1)
			{
				dp_inc[i]=dp_inc[j]+1;
				dp_prev_inc[i]=j;
			}
		}
		//cap nhat chi so cuoi va do dai
		if(dp_inc[i]>max_len_inc)
		{
			max_len_inc=dp_inc[i];
			end_idx_inc=i;
		}
	}

	//tao LDS
	vector<int> dp_dec(n,1);
	vector<int> dp_prev_dec(n,-1);

	int max_len_dec=0;
	int end_idx_dec=-1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j]&&dp_dec[i]<dp_dec[j]+1)
			{
				dp_dec[i]=dp_dec[j]+1;
				dp_prev_dec[i]=j;
			}
		}
		//cap nhat chieu dai - vi tri cuoi
		if(dp_dec[i]>max_len_dec)
		{
			max_len_dec=dp_dec[i];
			end_idx_dec=i;
		}
	}

	//tao chuoi INC hoac DEC dai nhat
	int max_len=0;
	vector<int> RES;
	if(max_len_dec>max_len_inc)
	{
		max_len=max_len_dec;
		if(end_idx_dec!=-1)
		{
			int cur_idx=end_idx_dec;
			while (cur_idx!=-1)
			{
				RES.push_back(a[cur_idx]);
				cur_idx=dp_prev_dec[cur_idx];
			}
		}

		reverse(RES.begin(), RES.end());
	}
	else
	{
		max_len=max_len_inc;
		if(end_idx_inc!=-1)
		{
			int cur_idx=end_idx_inc;
			while (cur_idx!=-1)
			{
				RES.push_back(a[cur_idx]);
				cur_idx=dp_prev_inc[cur_idx];
			}
		}

		reverse(RES.begin(), RES.end());
	}

	//xuat file
	ofstream Output("tapcon.out");
	Output<<max_len<<endl;
	for(size_t i=0;i<RES.size();i++)
	{
		Output<<RES[i]<<(i==RES.size()-1?"":" ");
	}

	Output.close();
}
