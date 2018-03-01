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
	int n;
	cin>>n;
	int st,ed;
	vi fs(0);
	int dff;
	if(n%4==0)
	{
		st=1;
		ed=n;
		dff = 0;
	} else if(n%4==1)
	{
		st=2;
		ed=n;
		fs.pb(1);
		dff = 1;
	} else if(n%4==2)
	{
		st = 3;
		ed = n;
		dff = 1;
		fs.pb(1);
	} else {
		st = 4;
		ed = n;
		dff = 0;
		fs.pb(3);
	}
	while(st<ed)
	{
		fs.pb(st);
		fs.pb(ed);
		st+=2;
		ed-=2;
	}
	cout<<dff<<endl;
	cout<<fs.size()<<" ";
	foi(fs.size())
	{
		cout<<fs[i]<<" ";
	}
	cout<<endl;
}