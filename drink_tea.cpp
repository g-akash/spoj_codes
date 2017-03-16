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


int main()
{
	int n,k,a,b;
	cin>>n>>k>>a>>b;
	if(min(a,b)==0&&max(a,b)>k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(min(a,b)!=0)
	{
		if(max(a,b)/(min(a,b)+1)>k||(max(a,b)/(min(a,b)+1)==k&&max(a,b)%(min(a,b)+1)!=0))
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	int ka=0,kb=0;
	string ans="";
	foi(n)
	{
		if(a>b)
		{
			if(ka<k)
			{
				ans+="G";
				ka++;
				kb=0;
				a--;
			}
			else
			{
				ans+="B";
				kb++;
				ka=0;
				b--;
			}
		}
		else
		{
			if(kb<k)
			{
				ans+="B";
				kb++;
				ka=0;
				b--;
			}
			else
			{
				ans+="G";
				ka++;
				kb=0;
				a--;
			}
		}
	}
	cout<<ans<<endl;
}