#include<iostream>
#include<algorithm>
#include<vector>
#include<vector>

using namespace std;

#define ll long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll n,p,var;
		cin>>n>>p;
		vector<ll> v;
		v.resize(n+1);
		v[0]=1;
		for(int j=1;j<=n;j++)
		{
			var=0;
			for(int k=j-1;k>=0&&k>j-1-p;k--){var+=v[k];var%=1000000009;}
			v[j]=var;
		}
		cout<<v[n]<<endl;
	}
}
