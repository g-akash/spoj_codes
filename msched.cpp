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


class cows
{
public:
	int g,d;

	bool operator<(const cows & c) const
	{
		if(d<c.d)return true;
		if(d==c.d&&g<c.g)return true;
		return false;
	}
};


int main()
{
	int n;
	cin>>n;
	vector<cows> vec;
	cows c;
	foi(n)
	{
		cin>>c.g>>c.d;
		vec.pb(c);
	}
	sort(vec.begin(),vec.end());
	int tim = vec[vec.size()-1].d;
	int x=vec.size()-1;
	mm(int,int) m;
	mm(int,int)::iterator it;
	int count = 0;
	int ans = 0;
	while(tim>0)
	{
		//cout<<tim<<endl;
		while(vec[x].d>=tim)
		{
			count+=1;
			m[vec[x].g]+=1;
			x--;
			if(x<0)break;
		}
		if(count>0)
		{
			it = m.end();
			
			it--;
			ans+=it->first;
			it->second-=1;
			if(it->second==0)m.erase(it);
			count-=1;
		}
		tim-=1;

	}
	cout<<ans<<endl;

}