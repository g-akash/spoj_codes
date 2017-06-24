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

int n,k;
vi vec;

vvi tmp;
vvi sell;
vi temp;


int get_profit(int a, int b)
{
	if(sell[a][b]!=-1)return sell[a][b];
	temp[a+1]=vec[a];
	int ans = vec[a+1]-temp[a+1];
	for(int i=a+2;i<=b;i++)
	{
		temp[i]=min(temp[i-1],vec[i-1]);
		ans = max(ans,vec[i]-temp[i]);
	}
	//cout<<a<<" "<<b<<" "<<ans<<endl;
	sell[a][b]=ans;
	return ans;
}

int max_profit(int x, int y)
{
	int var = 0;
	if(x>=n)return 0;
	if(y<=1)return 0;
	if(tmp[x][y]!=-1)return tmp[x][y];
	for(int i=x+1;i<n;i++)
	{
		int ver1 = get_profit(x,i),ver2=max_profit(i+1,y-2);
		int ver=ver1+ver2;
		
		var = max(ver,var);

	}
	tmp[x][y]=var;
	return var;
}


int main()
{
	
	cin>>n>>k;
	vec.resize(n);
	temp.resize(n);
	sell.resize(n);
	foi(n)cin>>vec[i];
	tmp.resize(n);
	foi(n)
	{
		tmp[i].resize(k+1);
		sell[i].resize(n);
		foj(k+1)tmp[i][j]=-1;
		foj(n)sell[i][j]=-1;
	}
	int ans = max_profit(0,k);

	cout<<max(0,ans)<<endl;

}