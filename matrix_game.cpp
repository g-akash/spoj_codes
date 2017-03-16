#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()

int n;

vi get_one(int x)
{
	vi ans;
	for(int i=1;i<=n;i++)
	{
		int var=i;
		foj(x)var/=2;
		if(var%2==1)ans.pb(i);

	}
	return ans;
}

vi get_zero(int x)
{
	vi ans;
	for(int i=1;i<=n;i++)
	{
		int var=i;
		foj(x)var/=2;
		if(var%2==0)ans.pb(i);

	}
	return ans;
}


int main()
{
	
	int var;
	cin>>n;
	vi lst;
	vvi os(10),zs(10);
	foi(10)
	{
		lst = get_one(i);
		if(lst.size()>0)
		{
			cout<<lst.size()<<endl;
			foj(lst.size())cout<<lst[j]<<" ";cout<<endl;
			foj(n){cin>>var;os[i].pb(var);}
		}
		else
		{
			foj(n){os[i].pb(2*1000000000);}
		}
		lst = get_zero(i);
		if(lst.size()<n)
		{
			cout<<lst.size()<<endl;
			foj(lst.size())cout<<lst[j]<<" ";cout<<endl;
			foj(n){cin>>var;zs[i].pb(var);}
		}
		else
		{
			foj(n){zs[i].pb(2*1000000000);}
		}
	}
	cout<<-1<<endl;
	//foi(os.size()){foj(os[0].size())cout<<os[i][j]<<" ";cout<<endl;}
	//foi(zs.size()){foj(zs[0].size())cout<<zs[i][j]<<" ";cout<<endl;}
	//cout<<os.size()<<os[0].size()<<endl;
	foi(n)
	{
		var=i+1;
		int ans=2000000001;
		foj(10)
		{
			if(var%2==0)ans=min(ans,os[j][i]);
			else ans=min(ans,zs[j][i]);
			var/=2;
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
