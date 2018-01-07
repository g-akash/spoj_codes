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
		vvll vec(n),ans(n);
		foi(n){vec[i].resize(n);ans[i].resize(n);}
		foi(n)
		{
			foj(n)cin>>vec[i][j];
			sort(vec[i].begin(),vec[i].end());
		}
		foi(n)ans[0][i]=vec[0][i];
		for(int i=1;i<n;i++)
		{
			ll curr_max = -1;
			for(int j=0;j<n;j++)
			{
				if(ans[i-1][n-1]==-1)
				{
					ans[i][j]=-1;
				}
				else if(vec[i][j]<=vec[i-1][0])
				{
					ans[i][j]=-1;
				} else if(vec[i][j]>vec[i-1][n-1])
				{
					ans[i][j]=vec[i][j]+ans[i-1][n-1];
				} else {
					int x = 0, y = n-1;
					while(y-x>1)
					{
						int mid = (x+y)/2;
						if(vec[i][j]>vec[i-1][mid])x=mid;
						else y = mid;
					}
					if(ans[i-1][x]!=-1)
						ans[i][j]=vec[i][j]+ans[i-1][x];
					else ans[i][j]=-1;

				}
				if(ans[i][j]>curr_max)curr_max=ans[i][j];
				else ans[i][j]=curr_max;

			}

		}
		cout<<ans[n-1][n-1]<<endl;

	}
}