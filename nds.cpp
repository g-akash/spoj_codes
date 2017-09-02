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
	ll t;
	cin>>t;
	//vi::iterator it;
	while(t--)
	{
		ll n,var;
		cin>>n;

		vll vec(0);
		if(n>=1)
		{
			cin>>var;
			vec.pb(var);
		}
		foi1(n-1)
		{
			cin>>var;
			if(var<=vec[0])vec[0]=var;
			else if(var>vec[vec.size()-1])vec.pb(var);
			else if(var==vec[vec.size()-1])continue;
			else 
			{
				int x=0,y=vec.size()-1;
				while(y-x>1)
				{
					int mid = (x+y)/2;
					if(vec[mid]>var)y=mid;
					else x=mid;
				}
				if(vec[x]<var)vec[y]=var;
			}
		}
		cin>>var;
		if(var<=0)cout<<-1<<endl;
		else if(vec.size()<var)cout<<-1<<endl;
		else cout<<vec[var-1]<<endl;
	}	
}