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

class por{
public:
	int st,ed;

	por()
	{
		st=0,ed=0;
	}
	por(int a, int b)
	{
		st=a;
		ed=b;
	}
};

bool comp(por p, por q)
{
	if(p.st<q.st)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,p;
		cin>>n>>k>>p;
		int a,b;
		vector<por> v1,v2;
		foi(k)
		{
			cin>>a>>b;
			por pe(a,b);
			v1.pb(pe);
		}
		foi(p)
		{
			cin>>a>>b;
			por pe(a,b);
			v2.pb(pe);
		}
		sort(v1.begin(),v1.end(),comp);
		sort(v2.begin(),v2.end(),comp);
		bool ans = true;
		foi(p)
		{
			bool is_present = false;
			foj(k)
			{
				if(v2[i].ed==v1[j].ed)
				{
					is_present=true;
					break;
				}
			}
			if(!is_present)
			{
				ans=false;
				break;
			}
		}
		if(ans)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}