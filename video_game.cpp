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
	int n,h,comm;
	cin>>n>>h;
	int currh=0,currpos=0;
	vi stacks(n);
	foi(n)
	{
		cin>>stacks[i];
	}
	cin>>comm;
	while(comm!=0)
	{

		if(comm==1)
		{
			if(currpos!=0)
			{
				currpos--;
			}
		}
		else if(comm==2)
		{
			if(!(currpos>=n-1))
			{
				currpos++;
			}
		}
		else if(comm==3)
		{
			if(stacks[currpos]!=0&&currh==0)
			{
				stacks[currpos]--;
				currh=1;
			}
		}
		else if(comm==4)
		{
			if(stacks[currpos]<h&&currh==1)
			{
				currh=0;
				stacks[currpos]+=1;
			}
		}
		cin>>comm;
	}
	foi(stacks.size())
	{
		cout<<stacks[i]<<" ";
	}
	cout<<endl;
}