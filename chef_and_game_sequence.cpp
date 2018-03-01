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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ce=0,co=0;
		int var;
		for(int i=0;i<n;i++)
		{
			cin>>var;
			if(var%2==0)ce+=1;
			else co+=1;
		}
		if(co>1)
		{
			if(co%2==0)
			{
				co=0;
				ce+=1;
			}
			else
			{
				co=1;
				ce+=1;
			}
		}
		if(ce>1)
		{
			ce=1;
		}
		cout<<co+ce<<endl;
	}
}