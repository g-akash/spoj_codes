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



class pos{
public:
	ll i,j,prod;
};

bool comp(pos p, pos q)
{
	if(p.prod<q.prod)return true;
	if(p.prod==q.prod&&p.i<q.i)return true;
	return false;
}


int main()
{
	ll n,m,var,tot=0;
	cin>>n>>m;
	vector<pos> order;
	pos p;
	foi(n)
	{
		foj(n)
		{
			cin>>var;
			tot+=var;
			p.i=(ll)(i+1);
			p.j=(ll)(j+1);
			p.prod = p.i*p.j;
			order.pb(p);
		}
	}
	sort(order.begin(),order.end(),comp);
	ll count = n*n-1;
	vvll vec(n+1);
	foi1(n)vec[i].resize(n+1);
	for(int i = order.size()-1;i>=0;i--)
	{
		if(count+m<=tot)
		{
			vec[order[i].i][order[i].j]=m;
			tot-=m;
			count--;
		}
		else
		{
			vec[order[i].i][order[i].j]=(tot-count);
			tot-=(tot-count);
			count--;
		}
	}
	
	foi1(n)
	{
		foj1(n)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
}