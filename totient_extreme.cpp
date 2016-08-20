#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define ll long long int

vector<ll> prims,a,b,ans;

void prime()
{
	for(int i=0;i<10005;i++){a[i]=1;b[i]=1;}
	for(ll i=2;i<10005;i++)
	{
		if(prims[i]==1)continue;
		for(ll j=2*i;j<10005;j+=i)
		{
			prims[j]=1;
			a[j]*=(i-1);
			b[j]*=i;
		}
	}
	for(ll i=4;i<10005;i++)
	{
		
		if(prims[i]==0)ans[i]=i-1;
		else ans[i]=(i*a[i])/b[i];
	
	}
	ans[0]=0;
	ans[1]=1;
	ans[2]=1;
	ans[3]=2;
	for(int i=1;i<10005;i++)
	ans[i]+=ans[i-1];
}

int main()
{
	prims.resize(10005);
	a.resize(10005);
	b.resize(10005);
	ans.resize(10005);
	prime();
	int t,var;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>var;
		cout<<ans[var]*ans[var]<<endl;
	}
}
