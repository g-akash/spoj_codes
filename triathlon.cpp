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


class even
{
public:
	int comp,rst;
};

bool comp(even p, even q)
{
	if(p.rst>q.rst)return true;
	return false;
}

int main()
{
	int n,a,b,c;
	cin>>n;
	vector<even> vec(n);
	even e;
	foi(n)
	{
		cin>>a>>b>>c;
		e.comp=a;
		e.rst = b+c;
		vec[i]=e;
	}
	sort(vec.begin(),vec.end(),comp);
	int ans=0,curr=0;
	foi(n)
	{
		if(curr+vec[i].comp+vec[i].rst>ans)
		{
			ans = curr+vec[i].comp+vec[i].rst;
		}
		curr+=vec[i].comp;
	}
	cout<<ans<<endl;

}