#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


#define ull unsigned long long int

vector<vector<ull> > v;

void calcu()
{
	v[1][0]=1;
	v[1][1]=1;
	for(int i=2;i<62;i++)v[1][i]=0;
	for(int i=2;i<62;i++)
	{
		v[i][0]=1;
		//cout<<i<<endl;
		for(int j=1;j<=i;j++)v[i][j]=v[i-1][j-1]+v[i-1][j];
		//	cout<<i<<endl;
	}
	return;
}

ull powi(ull n)
{
	ull ans=0,var=1;
	while(var!=n)
	{
		var*=2;ans++;
		//cout<<var<<endl;
	}
	return ans;
}

int main()
{
	 
	v.resize(62);
	for(int i=0;i<62;i++)v[i].resize(62);
	calcu();
	ull n,powiz,ans=0,t;
	cin>>t;
	for(int j=0;j<t;j++){
	cin>>n;
	ans=0;
	powiz=powi(n);
	for(ull i=0;i<powiz;i++)
	{
		if(i%2==1)ans+=v[i][i/2];
		}
	if(n!=2)	//if(powiz%2==0)ans++;
	cout<<ans<<endl;
	else cout<<1<<endl;
}
}