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


class eve
{
public:
	ll start, ed;
};


bool comp(eve p, eve q)
{
	if(p.ed<q.ed)return true;
	else if(p.ed==q.ed&&p.start>q.start)return true;
	return false;
}


int main()
{
	ll n,a,b;
	cin>>n;
	vector<eve> vec;
	foi(n)
	{
		cin>>a>>b;
		eve e;
		e.start=a;
		e.ed = a+b;
		vec.pb(e);

	}
	sort(vec.begin(),vec.end(),comp);
	ll curr_ed=-100000000,ans = 0;
	for(int i=0;i<vec.size();i++)
	{
		//cout<<vec[i].ed<<endl;
		if(vec[i].start>curr_ed)
		{
			ans+=(ll)1;
			curr_ed=vec[i].ed;
		}
	}
	cout<<ans<<" "<<endl;

}