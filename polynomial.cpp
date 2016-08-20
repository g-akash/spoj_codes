#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	long long int n;
	cin>>n;
	int cnt=1;
	while(n!=-1)
	{
		vector<long long int> v;
		vector<long long int> coeffs,ponts;
		coeffs.resize(n+1);
		long long int var,k;
		for(int i=0;i<=n;i++)
		{
			cin>>coeffs[i];
		}
		cin>>k;
		ponts.resize(k);
		for(int i=0;i<k;i++)
		{
			cin>>ponts[i];
		}
		v.resize(k);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<k;j++)
			{
				v[j]=v[j]*ponts[j]+coeffs[i];
			}
		}
		cout<<"Case "<<cnt<<":"<<endl;
		for(int i=0;i<k;i++)cout<<v[i]<<endl;
			cin>>n;cnt++;
	}
}