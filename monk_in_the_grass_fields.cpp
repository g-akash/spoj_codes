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
		ll n,k;
		cin>>n>>k;
		vvll vec(n);
		foi(n)vec[i].resize(n);
		vll rows(n),cols(n);
		foi(n)
		{
			foj(n)
			{
				cin>>vec[i][j];
				rows[i]+=vec[i][j];
				cols[j]+=vec[i][j];
			}
		}
		ll ans=0;
		foj(k)
		{
			ll rmin=0,cmin=0;
			foi(n)if(rows[i]<rows[rmin])rmin=i;
			foi(n)if(cols[i]<cols[cmin])cmin=i;
			if(rows[rmin]<cols[cmin])
			{
				ans+=rows[rmin];
				rows[rmin]+=n;
				foi(n)cols[i]+=1;
			}
			else
			{
				ans+=cols[cmin];
				cols[cmin]+=n;
				foi(n)rows[i]+=1;
			}
		}
		
		cout<<ans<<endl;
	}
}