#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vll vec(n);
		foi(n)cin>>vec[i];
		stack<ll> val,indl;
		vi ans(n);
		foi(n)ans[i]=-1;
		val.push(vec[n-1]);
		indl.push(n-1);
		for(int i=n-2;i>=0;i--)
		{
			while(!val.empty())
			{
				if(val.top()>=vec[i])
				{
					val.push(vec[i]);
					indl.push(i);
					break;
				}
				else
				{
					ans[indl.top()]=i;
					indl.pop();
					val.pop();
				}
			}
			if(val.empty())
			{
				val.push(vec[i]);
				indl.push(i);
			}
		}

		foi(n)
		{
			//cout<<i<<" "<<ans[i]<<endl;
			if(ans[i]==-1)cout<<i-0+1<<" ";
			else cout<<i-ans[i]<<" ";
		}
		cout<<endl;
	}
}