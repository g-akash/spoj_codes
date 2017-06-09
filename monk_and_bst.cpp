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
#include <unistd.h>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define foi1(n) for(ll i=1;i<=n;i++)
#define foj1(n) for(ll j=1;j<=n;j++)
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	ll l,s;
	scanf("%lld %lld",&l,&s);
	vll pws(63);
	pws[0]=1;
	foi1(62)pws[i]=pws[i-1]*2;
	ll sum = 0,diff = (pws[l])-1;
	foi(l-1)
	{
		//cout<<sum<<endl;
		sum= sum*2+ (pws[2*i+1])-1;
	}
	ll count=0;
	ll gmn=0,gmx=(pws[l-1])-1;
	ll mn=gmn,mx=gmx;
	//cout<<sum<<endl;
	s-=sum;
	if(s%diff==0)count=s/diff+1;
	else count=s/diff+1;
	// while(sum<=s)
	// {
	// 	sum+=diff;
	// 	count++;
	// }
	//cout<<count<<" count is here"<<endl;
	ll q;
	scanf("%lld",&q);
	ll typ,val;
	//cout<<count<<endl;
	//cout<<s+sum<<" "<<s+count*diff<<endl;
	//cout<<gmn+count<<" "<<gmx+count<<endl;
	foi(q)
	{
		mn=gmn;mx=gmx;
		scanf("%lld %lld",&typ,&val);
		string ans="";
		ll currval = (mx+mn)/2;
		//cout<<typ<<" "<<val<<endl;
		//cout<<"kk"<<endl;
		if(typ==0)
		{
			val-=count;
			while(currval!=val)
			{
				//cout<<ans<<" "<<mn<<" "<<mx<<" "<<currval<<" "<<val<<endl;
				if(currval<val)
				{
					ans+="r";
					mn=currval+1;
					currval=(mn+mx)/2;
				}
				else
				{
					ans+="l";
					mx=currval;
					currval=(mn+mx)/2;
				}
				//usleep(10000);
			}
			if(ans=="")printf("root\n");
			else printf("%s\n",ans.c_str());
		}
		else
		{
			//cout<<count<<endl;
			ans="";
			while(val!=1)
			{
				if(val%2==1)
				{
					ans=ans+"r";
				}
				else
				{
					ans=ans+"l";
				}
				val/=2;
			}

			for(ll j=ans.length()-1;j>=0;j--)
			{
				if(ans[j]=='l')
				{
					mx=currval;
					currval=(mn+mx)/2;
				}
				else
				{
					mn=currval+1;
					currval=(mn+mx)/2;
				}
			}
			printf("%lld\n",currval+count);

		}
	}

}