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

int n;
vector<string> vec;
vvi done;


bool inspect(int x, int y, int len)
{
	for(int i=-len;i<=len;i++)
	{
		if(i==0)continue;
		if(vec[x+i][y-len]!='0'||vec[x+i][y+len]!='0')return false;
		if(vec[x-len][y+i]!='0'||vec[x+len][y+i]!='0')return false;
	}
	if(vec[x-len][y]!='1'||vec[x+len][y]!='1'||vec[x][y-len]!='1'||vec[x][y+len]!='1')return false;
	return true;
}


int max_plus_matrix(int x, int y)
{
	int ans = 0;
	for(int i=1;i<n;i++)
	{
		if(x-i<0||x+i>=n||y-i<0||y+i>=n)break;
		if(!inspect(x,y,i))break;
		ans+=1;
	}
	return ans;
}

void mark_done(int x, int y, int len)
{
	for(int i=x-len;i<=x+len;i++)
	{
		for(int j=y-len;j<=y+len;j++)
		{
			done[i][j]=1;
		}
	}
	return;
}
int main()
{
	
	cin>>n;
	vec.resize(n);
	done.resize(n);
	foi(n)
	{
		cin>>vec[i];
		done[i].resize(n);
	}
	int ans = 0,len;
	foi(n)
	{
		foj(n)
		{
			if(done[i][j]||vec[i][j]=='0')continue;
			len = max_plus_matrix(i,j);
			ans+=len;
			//cout<<len<<endl;
			mark_done(i,j,len);
		}
	}
	cout<<ans<<endl;


}