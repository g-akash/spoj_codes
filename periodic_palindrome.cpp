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


string get_string(int x)
{
	string ans = "a";
	for(int i=1;i<x-1;i++)
	{
		ans+="b";
	}
	ans+="a";
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n>>p;
		if(p<=2)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			string str = get_string(p);
			foi(n/p)cout<<str;
			cout<<endl;
		}
	}
}