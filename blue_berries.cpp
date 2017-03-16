#include<iostream>
#include<vector>


using namespace std;

int a[1002][1002];
vector<int> b;
int dist(int n, int k)
{
	if(n<0||k<0)return 0;
	if(n==0){a[n][k]=0;return 0;}
	else if(k<=0){a[n][k]=0;return 0;}
	else if(a[n][k]>=0)return a[n][k];
	else 
	{
		int x,y,z;
		if(b[n-1]<=k){x=dist(n-2,k-b[n-1])+b[n-1];}
		else x=-100000000;
		y=dist(n-1,k);
		z=max(x,y);
		a[n][k]=z;
		return z;
	}
}
	

int main()
{
	int t;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		int n,k;
		cin>>n>>k;
		b.resize(n);
		for(int i=0;i<n;i++)cin>>b[i];
		for(int i=0;i<1002;i++)
		{
			for(int j=0;j<1002;j++)a[i][j]=-1;
		}
		cout<<"Scenario #"<<ko+1<<": "<<dist(n,k)<<endl;
	}
}
