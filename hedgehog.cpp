#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


vector<ll> ta;
vector<vector<ll> > ne;

void calct(int x){
	//cout<<x<<endl;
	if(ta[x]>0)return;
	ll ans=1;
	foi(ne[x].size()){
		if(ne[x][i]<x)calct(ne[x][i]);
		if(ne[x][i]<x)ans=max(ans,ta[ne[x][i]]+1);
	}
	ta[x]=ans;
	return;
}



int main()
{
	int n,m;
	cin>>n>>m;
	ta.resize(n+1);
	ne.resize(n+1);
	foi(m){
		int a,b;
		cin>>a>>b;
		ne[a].pb(b);
		ne[b].pb(a);
	}
	foi(n+1){
		calct(i);
	}
	ll ans=0;
	foi1(n){
		ans=max(ans,(ll)(ne[i].size()*ta[i]));
	}
	cout<<ans<<endl;

}