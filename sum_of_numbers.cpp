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
		int mx=1;
		foi(n)mx*=2;
		vi vec(n);
		foi(n)cin>>vec[i];
		int finval;
		cin>>finval;
		bool done=false;
		for(int i=0;i<mx;i++)
		{
			int var = i;
			int tmp=0;
			foj(n)
			{
				if(var%2==1)tmp+=vec[j];
				var/=2;
			}
			if(tmp==finval)
			{
				cout<<"YES"<<endl;
				done = true;
				break;
			}
		}
		if(!done)cout<<"NO"<<endl;
	}
}