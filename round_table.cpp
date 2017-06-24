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

vvi ans(2);
vi val;
int n;


int dowork(int a, int b)
{
	if(b==n-1)return ans[a][b];
	if(ans[a][b]!=-1)return ans[a][b];
	else if(a==0)
	{
		int tmp = val[b];
		int tmp2 = dowork(1,b+1);
		tmp+=tmp2;
		ans[a][b]=tmp;
		return tmp;
	}
	else
	{
		int tmp = val[b];
		int tmp1 = dowork(1,b+1);
		int tmp2 = dowork(0,b+1);
		tmp1+=tmp;
		ans[a][b] = min(tmp1,tmp2);
		return ans[a][b];
	}
}

int main()
{
	
	cin>>n;
	foi(2)ans[i].resize(n);
	foi(2)foj(n)ans[i][j]=-1;
	val.resize(n);
	foi(n)cin>>val[i];
	ans[0][n-1]=val[n-1];
	ans[1][n-1]=val[n-1];
	int val1 = dowork(1,0);


	//prepare the stuff for the second time.
	foi(2)foj(n)ans[i][j]=-1;
	ans[0][n-1]=val[n-1];
	ans[1][n-1]=0;
	int val2 = dowork(1,1);
	//cout<<val2<<endl;
	val2 += val[0];
	//cout<<val1<<" "<<val2<<endl;
	cout<<min(val1,val2)<<endl;

}