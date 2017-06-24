#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
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
	int n;
	cin>>n;
	vi vec(n);
	vi ans(n);
	foi(n)cin>>vec[i];
	int final_ans=1;
	ans[0]=1;
	foi1(n-1)
	{
		ans[i]=1;
		for(int j=0;j<i;j++)
		{
			if(vec[i]%vec[j]==0&&ans[j]+1>ans[i])ans[i]=ans[j]+1;
		}
		final_ans=max(final_ans,ans[i]);
	}
	cout<<final_ans<<endl;
}