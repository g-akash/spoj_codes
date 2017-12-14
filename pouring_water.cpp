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


class node{
public:
	int wa,wb,steps;
	node()
	{
		wa=0,wb=0,steps=0;
	}
	node(int x, int y, int z)
	{
		wa=x;
		wb=y;
		steps=z;
	}
};

int a,b,c;

umm(ll,ll) um;

bool eqls(node y)
{
	if(y.wb==c&&b>=c)return true;
	if(y.wa==c&&a>=c)return true;
	return false;
}

bool done(node n)
{
	ll x = ((ll)n.wa)*(ll)1000000+(ll)n.wb;
	if(um.find(x)!=um.end())
	{
		return true;
	}
	um[x]=1;
	return false;
}

int gcd(int a, int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}




int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		um.clear();
		cin>>a>>b>>c;
		if(c%gcd(a,b)!=0||(c>a&&c>b))
		{
			cout<<-1<<endl;
			continue;
		}
		node n;
		queue<node> q;
		q.push(n);
		bool ans = true;
		while(true)
		{
			n = q.front();
			q.pop();
			if(done(n))continue;
			if(eqls(n))
			{
				cout<<n.steps<<endl;
				ans = false;
				break;
			}
			int st = n.steps;
			node n1(n.wa,0,st+1),n2(0,n.wb,st+1),n3(a,n.wb,st+1),n4(n.wa,b,st+1);
			q.push(n1);
			q.push(n2);
			q.push(n3);
			q.push(n4);
			if(a-n.wa>=n.wb)
			{
				node n5(n.wa+n.wb,0,st+1);
				q.push(n5);
			}
			else
			{
				node n6(a,n.wb-(a-n.wa),st+1);
				q.push(n6);
			}
			if(b-n.wb>=n.wa)
			{
				node n7(0,n.wa+n.wb,st+1);
				q.push(n7);
			}
			else
			{
				node n8(n.wa-(b-n.wb),b,st+1);
				q.push(n8);
			}

		}
	}
}