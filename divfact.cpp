#include<iostream>
#include<vector>

using namespace std;

#define ll long long

vector<ll int> v;

void prims()
{
	for(int i=0;i<50500;i++)v[i]=0;
	v[2]=0;
	for(int i=2;i<50500;i++)
	{
		if(v[i]==1)continue;
		for(int j=2*i;j<50500;j+=i)v[j]=1;
	}
}

int main()
{
	v.resize(50500);
	prims();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<ll int> facs;
		ll  int n,var;
		cin>>n;
		facs.resize(50500);
		for(long long int j=2;j<50500;j++)
		{
			if(v[j]==1)continue;
			var=n;
			while(var>0)
			{
				var/=j;
				facs[j]+=var;
			}
			//cout<<j<<" "<<facs[j]<<endl;
		}
		long long int ans=1;
		for(int j=2;j<50500;j++)
		{
			if(v[j]==0&&facs[j]!=0)
			{
				ans*=(facs[j]+1);
				ans=ans%1000000007;
			}
		}
		cout<<ans<<endl;
	}
}
