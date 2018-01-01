#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
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
		ll n,m;
		cin>>n>>m;
		ll quo = n/m;
		ll rem = n%m;
		ll ans = 0;
		if(m%2==0)
		{
			ans+=(quo*(quo-1))/2;
			
			if(rem>=m/2)
			{
				ans+=((quo+1)*(quo))/2;
			}
			else ans+=(quo*(quo-1))/2;
			
			if(rem==0)
			{
				ans+=(m/2-1)*(quo*quo);
			}
			else if(rem==m/2)
			{
				ans+=(m/2-1)*(quo*(quo+1));
			}
			else if(rem>0&&rem<m/2)
			{
				ans+=(rem)*(quo*(quo+1));
				ans+=(m/2-1-rem)*(quo*quo);
			}
			else if(rem>m/2)
			{
				ans+=(rem-m/2)*(quo+1)*(quo+1);
				ans+=(m-1-rem)*(quo*(quo+1));
			}
		}
		else
		{
			
			ans+=(quo*(quo-1))/2;
			if(rem<=m/2)
			{
				ans+=(rem)*(quo+1)*(quo);
				ans+=(m/2-rem)*(quo*quo);
			}
			else
			{
				ans+=(rem-m/2)*(quo+1)*(quo+1);
				ans+=(m-1-rem)*(quo*(quo+1));
			}

		}

		cout<<ans<<endl;
	}
}