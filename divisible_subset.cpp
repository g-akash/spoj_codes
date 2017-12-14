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
		ll n,var;
		cin>>n;
		vll vals(n);
		vvll indx(n);
		ll curr=0;
		foi(n)
		{
			cin>>var;
			curr+=var;
			curr%=n;
			indx[curr].pb((ll)(i+1));
		}
		if(indx[0].size()>0)
		{
			int lim = indx[0][0];
			cout<<lim<<endl;
			for(int i=1;i<=lim;i++)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				if(indx[i].size()>1)
				{
					int strt = indx[i][0]+1,ed = indx[i][1];
					cout<<ed-strt+1<<endl;
					for(int j=strt;j<=ed;j++)cout<<j<<" ";
						cout<<endl;
					break;
				}
			}
		}

	}
}