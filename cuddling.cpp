#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define vi vector<ll>


string convert(ll a, ll b)
{
	return to_string(min(a,b))+"#"+to_string(max(a,b));
}

int main()
{
	ll q;
	cin>>q;
	umm(string,ll) um;
	foi(q)
	{
		ll typ,a,b,c;
		cin>>typ;
		if(typ==1)
		{
			cin>>a>>b>>c;
			vi x,y;
			while(a>0)
			{
				x.pb(a);
				a/=2;
			}
			while(b>0)
			{
				y.pb(b);
				b/=2;
			}
			ll s1=x.size()-1,s2=y.size()-1,strt;
			while(x[s1]==y[s2])
			{
				s1--;
				s2--;
			}
			s1++;
			s2++;
			//cout<<strt<<endl;
			strt=s1;
			for(ll j=strt;j>0;j--)
			{
				string s = convert(x[j],x[j-1]);
				//cout<<s<<endl;
				if(um.find(s)==um.end())um[s]=c;
				else um[s]+=c;
			}
			strt=s2;
			for(ll j=strt;j>0;j--)
			{
				string s = convert(y[j],y[j-1]);
				//cout<<s<<endl;
				if(um.find(s)==um.end())um[s]=c;
				else um[s]+=c;
			}

		}
		else
		{
			cin>>a>>b;
			vi x,y;
			while(a>0)
			{
				x.pb(a);
				a/=2;
			}
			while(b>0)
			{
				y.pb(b);
				b/=2;
			}
			ll s1=x.size()-1,s2=y.size()-1,strt;
			while(x[s1]==y[s2])
			{
				s1--;
				s2--;
			}
			s1++;
			s2++;
			//cout<<strt<<endl;
			strt=s1;
			ll ans=0;
			for(ll j=strt;j>0;j--)			
			{
				string s = convert(x[j],x[j-1]);
				//cout<<s<<"oho"<<endl;
				if(um.find(s)==um.end())ans+=0;
				else ans+=um[s];
				//cout<<s<<" "<<um[s]<<endl;
			}
			strt=s2;
			for(ll j=strt;j>0;j--)
			{
				string s = convert(y[j],y[j-1]);
				//cout<<s<<"oho"<<endl;
				if(um.find(s)==um.end())ans+=0;
				else ans+=um[s];
				//cout<<s<<" "<<um[s]<<endl;
			}
			cout<<ans<<endl;
		}
	}
}




