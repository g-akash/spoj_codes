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
	int n,var;
	cin>>n;
	stack<int> brac,pos;
	int maxd=0,maxdpos=1,maxs=0,maxspos=1,currd=0,currl=0;
	foi1(n)
	{
		cin>>var;
		if(var==1)
		{
			currd++;
			currl++;
			if(currd>maxd)
			{
				maxd=currd;
				maxdpos=i;
			}
			brac.push(1);
			pos.push(i);

		}
		else
		{
			int x=pos.top();
			pos.pop();
			brac.pop();
			currd--;
			if(i-x+1>maxs)
			{
				maxs=i-x+1;
				maxspos=x;
			}
		}
	}
	cout<<maxd<<" "<<maxdpos<<" "<<maxs<<" "<<maxspos<<endl;
}