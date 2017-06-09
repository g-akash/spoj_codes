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



class book
{
public:
	int hght,row;
};

bool comp(book p, book q)
{
	if(p.hght>q.hght)return true;
	return false;

}

int main()
{

	int n,k;
	cin>>n>>k;
	book var;
	vector<book> vec,r1,r2;
	var.row=1;
	foi(n)
	{
		cin>>var.hght;
		vec.pb(var);
	}
	var.row=2;
	foi(n)
	{
		cin>>var.hght;
		vec.pb(var);
	}
	sort(vec.begin(),vec.end(),comp);
	int tot=0,ff=0,fs=0;
	foi(2*n)
	{
		if(tot==n)
		{
			r2.pb(vec[i]);
			continue;
		}
		tot++;
		if(vec[i].row==1)
		{
			if(ff<k)
			{
				r1.pb(vec[i]);
				ff++;
			}
			else if(ff<=k&&fs<=k)
			{
				r1.pb(vec[i]);
				ff++;
			}
			else if(fs<=k)
			{
				r1.pb(vec[i]);
				ff++;
			}
			else
			{
				r2.pb(vec[i]);
			}
		}
		else
		{
			if(fs<k)
			{
				r1.pb(vec[i]);
				fs++;
			}
			else if(fs<=k&&ff<=k)
			{
				r1.pb(vec[i]);
				fs++;
			}
			else if(ff<=k)
			{
				r1.pb(vec[i]);
				fs++;
			}
			else
			{
				r2.pb(vec[i]);
			}
		}

	}
	cout<<r1[0].hght+r2[0].hght<<endl;

}