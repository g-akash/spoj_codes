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


vvi ans(3);
vi vec;
int n;


void dowork(int a, int b)
{
	if(ans[a][b]!=-1)return;
	if(b==n-1)
	{
		if(a==0)
		{
			ans[a][b]=vec[n-1];
			return;
		}
		else
		{
			ans[a][b]=0;
			return;
		}
	}
	if(a==0)
	{
		int curr = vec[b];
		dowork(2,b+1);
		ans[a][b]=curr+ans[2][b+1];
		return;
	}
	else
	{
		int var = vec[b];
		dowork(a-1,b+1);
		dowork(2,b+1);
		int tmp1 = ans[a-1][b+1], tmp2 = ans[2][b+1];
		ans[a][b]=min(tmp1,tmp2+var);
		return;
	}
	
}


int main()
{
	
	cin>>n;
	vec.resize(n);
	foi(n)cin>>vec[i];
	foi(3)ans[i].resize(n);
	foi(3)
	{
		foj(n)ans[i][j]=-1;
	}
	dowork(2,0);
	dowork(1,0);
	dowork(0,0);
	cout<<min(ans[0][0],min(ans[1][0],ans[2][0]))<<endl;

}