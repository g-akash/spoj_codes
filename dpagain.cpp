#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > ans;
vector<int> v;

void doit(int n, int k)
{
	cout<<n<<" "<<k<<endl;
	if(n==0)return;
	if(k==0)return;
	int a,b,c;
	if(ans[n][k-1]==-100)doit(n,k-1);
	a=ans[n][k-1];
	if(n-k>=0&&v[k-1]!=-1){if(ans[n-k][k]==-100)doit(n-k,k);b=ans[n-k][k];}
	else b=ans[n][k-1];
	a=min(a,b);
	ans[n][k]=a+v[k-1];
	return;
}

int main()
{
	int t;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		int n,k;
		cin>>n>>k;
		
		v.resize(k);
		for(int i=0;i<k;i++)cin>>v[i];
		//vector<vector<int> > ans;
		ans.resize(n+1);
		for(int i=0;i<=n;i++)ans[i].resize(k+1);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=k;j++)ans[i][j]=-100;
		}
		for(int i=0;i<=k;i++)
		{
			ans[0][i]=0;
		}
		for(int i=0;i<=n;i++)
		{
			ans[i][0]=-1;
		}
		ans[0][0]=0;
		doit(n,k);
		cout<<ans[n][k]<<endl;
	}
}
