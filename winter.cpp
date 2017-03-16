#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

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


class seg
{
public:
	int days,dec;
};

bool comp(seg p, seg q)
{
	if(p.days<q.days)return true;
	else if(p.days==q.days&&p.dec==2&&q.dec==1)return true;
	return false;

}

int main()
{
	int n,k,var;
	bool done=false;
	vi vec;
	vector<seg> parts;
	cin>>n>>k;
	foi(n)
	{
		if(done)
		{
			cin>>var;
			vec.pb(var);
		}
		else
		{
			cin>>var;
			if(var>=0)continue;
			done=true;
			vec.pb(var);
		}
	}
	var=0;
	seg s,spc;
	int tot = vec.size();
	foi(vec.size())
	{
		if(vec[i]>=0)
		{
			var++;
		}
		else if(vec[i]<0)
		{
			if(var>0)
			{
				s.days=var;
				s.dec=2;
				parts.pb(s);
				var=0;
			}
		}
	}
	spc.dec=0;
	spc.days=0;
	if(var>0)
	{
		spc.dec=1;
		spc.days=var;
		//parts.pb(s);
	}
	int ans=0;
	if(vec.size()>0)ans=1;
	var=parts.size()-1;
	sort(parts.begin(),parts.end(),comp);
	while(tot>k&&var>=0)
	{
		if(tot-spc.days<=k)
		{
			tot-=spc.days;
			ans+=spc.dec;
			spc.days=0;
			spc.dec=0;
			break;
		}
		tot-=parts[var].days;
		ans+=parts[var].dec;
		var--;
	}
	if(tot>k)
	{
		tot-=spc.days;
		ans+=spc.dec;
	}
	if(tot<=k)cout<<ans<<endl;
	else cout<<-1<<endl;





}