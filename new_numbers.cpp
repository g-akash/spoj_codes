#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

vector<vector<ll> > vec;
vi dig;

void calc(int x, int y)
{
	if(x==1&&y!=0)
		{
			vec[x][y] = 10-y;
			return;
		}
	else if(x==1&&y==0)
	{
		vec[x][y]=9;
		return;
	}
	if(vec[x][y]!=-1)return;
	ll sum=0;
	for(int i=y;i<10;i++)
	{
		calc(x-1,i);
		sum+=vec[x-1][i];
	}
	vec[x][y]=sum;
	return;

}

bool incr()
{
	foi(dig.size()-1)if(dig[i]>dig[i+1])return false;
	return true;
}

int calcu(int x)
{
	ll ans=0;
	int start=-1;
	foi(x)start=max(dig[i],start);
	if(x>=dig.size()&&incr())return 1;
	else if(x>=dig.size()) return 0;
	
	for(int i=start;i<dig[x];i++)
	{
		if(vec[dig.size()-x][i]!=-1)
		{
			if(i!=9)ans+=vec[dig.size()-x][i]-vec[dig.size()-x][i+1];
			else ans+=vec[dig.size()-x][i];
		}
	}
	ans+=calcu(x+1);
	return ans;
}


int main()
{
	vec.resize(19);
	foi(19)
	{
		vec[i].resize(10);
		foj(10)vec[i][j]=-1;
	}
	foi(10)
	{
		calc(18,i);
	}
	
	ll n;
	cin>>n;
	
	while(n!=0)
	{
		dig.insert(dig.begin(),n%10);
		n/=10;
	}
	ll ans=0;
	foi(dig[0])
	{
		//cout<<i<<" "<<vec[dig.size()][i]<<endl;
		if(vec[dig.size()][i]!=-1)
		{
			if(i!=9)ans+=vec[dig.size()][i]-vec[dig.size()][i+1];
			else ans+=vec[dig.size()][i];
		}
	}
	ans+=calcu(1);
	cout<<ans<<endl;


}