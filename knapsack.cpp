#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> szs,vals;
vector<vector<int> > ans;

void doit(int n, int s)
{
	if(n==0||s==0){ans[n][s]=0;return;}
	if(n<=0||s<=0)return ;
	if(ans[n][s]>=0)return ;
	int a,b=0;
	doit(n-1,s);
	a=ans[n-1][s];
	if(s-szs[n]>=0){doit(n-1,s-szs[n]);b=ans[n-1][s-szs[n]]+vals[n];}
	ans[n][s]=max(a,b);
	return ;
}

int main()
{
	int s,n;
	cin>>s>>n;
	szs.resize(n+1);
	vals.resize(n+1);
	for(int i=1;i<=n;i++)cin>>szs[i]>>vals[i];
	ans.resize(n+1);
	for(int i=0;i<=n;i++)ans[i].resize(s+1);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=s;j++)
			ans[i][j]=-1;
	}
	doit(n,s);
	cout<<ans[n][s]<<endl;
}