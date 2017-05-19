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


class player
{
public:
	int g,s,b;
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,var;
		cin>>n;
		vector<player> vec(n);
		player p;
		int tg=0,ts=0,tb=0,mm=-1;
		foi(n)
		{
			cin>>vec[i].g>>vec[i].s>>vec[i].b;
			tg+=vec[i].g;
			ts+=vec[i].s;
			tb+=vec[i].b;
			mm=max(mm,vec[i].g+vec[i].s+vec[i].b);
		}
		cout<<max(mm,max(tg,max(ts,tb)))<<endl;

	}
}