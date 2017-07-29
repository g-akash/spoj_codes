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


int n;
vi g1,g2;

vi done;
vvi vals;


vi get_ans(int a)
{
	vi tmpans(1);
	tmpans[0]=0;
	if(a>=n)return tmpans;
	if(done[a])return vals[a];
	vi val1 = get_ans(a+1);
	vi val;
	int dff = g1[a]-g2[a];
	foi(val1.size())
	{
		val.pb(val1[i]+dff);
		val.pb(val1[i]-dff);
	}
	sort(val.begin(),val.end());
	vi ans;
	ans.pb(val[0]);
	foi1(val.size()-1)if(val[i]!=val[i-1])ans.pb(val[i]);
	return ans;

}

int main()
{
	cin>>n;
	g1.resize(n);
	g2.resize(n);
	done.resize(n);
	vals.resize(n);
	foi(n)
	{
		done[i]=0;
	}
	foi(n)cin>>g1[i]>>g2[i];

	vi diff = get_ans(0);
	int ans=1000000000;
	foi(diff.size())if(abs(diff[i])<abs(ans))ans=abs(diff[i]);
	cout<<ans<<endl;
}