#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	int m,n,l,ln,st;
	cin>>n>>m>>l;
	if(l%(2*m)==0)
	{
		ln=l/(2*m);
		st=l-(ln-1)*2*m;
	}
	else
	{
		ln=l/(2*m)+1;
		st=l-(ln-1)*2*m;
	}
	cout<<ln<<" ";
	if(st%2==0)
	{
		cout<<st/2<<" R"<<endl;
	}
	else cout<<st/2+1<<" L"<<endl;
}