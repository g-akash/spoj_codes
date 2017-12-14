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
#include <ctime>

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


vll wm;


void sort_it(vector<ll> vec,ll &ans)
{
	if(vec.size()<=1)
	{
		ans=(ll)0;
		return ;
	}
	ll pos = rand()%(ll)vec.size();
	ll hs = vec[pos];
	vll v1,v2;
	//cout<<pos<<endl;
	for(ll i=0;i<pos;i++)
	{
		if(vec[i]<hs)
		{
			v1.pb(vec[i]);
			ans+=(ll)v2.size();
		}
		else 
		{
			v2.pb(vec[i]);
			ans+=(ll)1;
		}
	}

	for(ll i=pos+1;i<vec.size();i++)
	{
		if(vec[i]<hs)
		{
			v1.pb(vec[i]);
			ans+=(ll)(v2.size()+1);
		}
		else v2.pb(vec[i]);
	}
	ll a1=0,a2=0;
	//cout<<pos<<" "<<v1.size()<<" "<<v2.size()<<endl;
	sort_it(v1,a1);
	
	sort_it(v2,a2);
	//cout<<"vec ";
	// foi(vec.size())cout<<vec[i]<<" ";
	// cout<<endl;
	// cout<<pos<<endl;
	// cout<<vec.size()<<" "<<ans<<" "<<a1<<" "<<a2<<endl;
	ans+=a1;
	ans+=a2;
	//cout<<ans<<" this is sparta"<<endl;
	return;

}

bool comp(pair<ll,ll> p, pair<ll,ll> q)
{
	if(p.first<q.first)return true;
	return false;
}


int main()
{
	ll n;
	cin>>n;
	ll m,l;
	vector<pair<ll,ll> > vp;
	foi(n)
	{
		cin>>m>>l;
		pair<ll,ll> p(m,l);
		vp.pb(p);

		
	}
	sort(vp.begin(),vp.end(),comp);
	foi(vp.size())
	{
		wm.pb(vp[i].second);
	}
	//srand((unsigned)time(0));
	ll ans = 0;
	//sort(wm.begin(),wm.end());
	sort_it(wm,ans);
	cout<<ans<<endl;

}