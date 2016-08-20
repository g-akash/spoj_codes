#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define ull unsigned long long
vector<vector<ull int> > ans;

ull int ansi(ull int n, ull int r)
{
	if(r==0)return 1;
	if(n<r)return 0;
	if(ans[n][r]>0)return ans[n][r];
	ull int ans1 =ansi(n-1,r-1),ans2=ansi(n-1,r);
	ans[n][r]=(ans1+ans2)%10000007;
	return (ans1+ans2)%10000007;
}

int main()
{
	ull int n,r;
	cin>>n>>r;
	if(n<r)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	n-=1;
	r-=1;
	
	ans.resize(n+1);
	for(int i=0;i<=n;i++)ans[i].resize(r+1);
	cout<<ansi(n,r)<<endl;

}