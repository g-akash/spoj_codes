#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>

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
	int n,k,q;
	cin>>n>>k>>q;
	vi ma(n+1);
	foi1(n)cin>>ma[i];
	map<int,int> m;
	int curr=0,tv,a,b;
	foi(q)
	{
		cin>>a>>b;
		if(a==2)
		{
			tv=ma[b];
			if(m.find(tv)!=m.end())cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else
		{
			tv=ma[b];
			if(m.find(tv)!=m.end())continue;
			else
			{
				m[tv]=1;
				curr++;
				if(curr>k)
				{
					m.erase(m.begin());
					curr--;
				}
			}
		}
	}

}