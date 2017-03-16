#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vi >
#define foi(x) for(int i=0;i<x;i++)



vii vec;
vi cnt;
vector<double> res;
void calc_child(int x)
{
	int ans=0;
	foi(vec[x].size())
	{
		calc_child(vec[x][i]);
		ans+=cnt[vec[x][i]];
	}
	ans+=1;
	cnt[x]=ans;
	//cout<<x<<" "<<cnt[x]<<endl;
	return;
}

void calc_tim(int x)
{
	double tot_chld=0;
	foi(vec[x].size())
	{
		tot_chld+=cnt[vec[x][i]];
	}
	foi(vec[x].size())
	{
		res[vec[x][i]]=1.0+res[x]+double(tot_chld-cnt[vec[x][i]])/2.0;
		calc_tim(vec[x][i]);
	}
	return;
}


int main()
{
	int n,var;
	cin>>n;
	
	
	vec.resize(n+1);
	res.resize(n+1);
	cnt.resize(n+1);
	for(int i=2;i<=n;i++)
	{
		cin>>var;
		vec[var].push_back(i);
	}
	calc_child(1);
	res[1]=1.0;
	for(int i=2;i<=n;i++)
	{
		res[i]=0.0;
	}
	calc_tim(1);
	for(int i=1;i<=n;i++)
	{
		cout<<fixed<<setprecision(8)<<res[i]<<" ";
	}
	cout<<endl;
}