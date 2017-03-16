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


int main()
{
	int t;
	cin>>t;
	foi(t)
	{
		int n;
		cin>>n;
		vi vec(n);
		foj(n)cin>>vec[j];
		sort(vec.begin(),vec.end());
		int y=n-1,x=0;
		int ans=0,var=0,curr=0;
		cout<<"Case #"<<i+1<<": ";
		while(y>=x)
		{
			if(var>=50)
			{
				ans++;
				curr=0;
				var=curr;
			}
			else if(curr==0)
			{
				curr=vec[y];
				var=curr;
				y--;
			}
			else
			{
				var+=curr;
				x++;

			}
		}
		if(var>=50)ans++;
		cout<<ans<<endl;
	}
}