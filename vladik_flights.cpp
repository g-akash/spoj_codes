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
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	s="M"+s;
	if(s[a]==s[b])cout<<0<<endl;
	else
	{
		int prev=-100000000,nex=100000000;
		for(int i=b;i<=n;i++)
		{
			if(s[i]==s[a])
			{
				nex=i;
				break;
			}
		}
		for(int i=b;i>=0;i--)
		{
			if(s[i]==s[a])
			{
				prev=i;
				break;
			}
		}
		cout<<1<<endl;
	}
}