#include<bits/stdc++.h>


using namespace std;

#define ll long long int

vector<ll> parent,sizes;


class streets
{
public:
	ll start,end,length;
};

ll find_root(ll a)
{
	if(parent[a]==-1)return a;
	ll p = find_root(parent[a]);
	parent[a]=p;
	return p;
}

bool merge(ll a, ll b)
{
	ll p1=find_root(a);
	ll p2=find_root(b);
	if(p1==p2)return false;
	ll sz1=sizes[p1],sz2=sizes[p2];
	if(sz1>=sz2){parent[p2]=p1;sizes[p1]+=sz2;}
	else{parent[p1]=p2;sizes[p2]+=sz1;}
	return true;
}

bool comp(streets p, streets q)
{
	if(p.length<q.length)return true;
	return false;
}


int main()
{
	ll t;
	t=1;
	for(ll ko=0;ko<t;ko++){
	ll p,n,m,a,b,c,ans=0;
	cin>>n>>m;
	p=1;
	parent.resize(n+1);
	sizes.resize(n+1);
	for(ll i=0;i<=n;i++)
	{
		parent[i]=-1;
		sizes[i]=1;
	}
	vector<streets> vec;
	vec.resize(m);
	for(ll i=0;i<m;i++)
	{
		cin>>vec[i].start>>vec[i].end>>vec[i].length;
	}
	//cout<<"hehe"<<endl;
	sort(vec.begin(),vec.end(),comp);
	//cout<<"hehe"<<endl;
	for(ll i=0;i<vec.size();i++)
	{
		if(merge(vec[i].start,vec[i].end))ans+=vec[i].length*p;
	}
	cout<<ans<<endl;
}

}