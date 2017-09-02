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


class tour
{
public:
	int pos,val;
	tour(int a=0,int b=0)
	{
		pos = a;
		val = b;
	}

	bool operator ==(tour const & t) const
	{
		if(pos==t.pos&&val==t.val)return true;
		return false;
	}
};


int main()
{
	int n,m,var,ver;
	cin>>n>>m;
	int len = (int)pow(2,n);
	//cout<<len<<endl;
	vector<tour> vec(len);
	foi(len)
	{
		cin>>var;
		tour t(i+1,var);
		//cout<<t.pos<<" print "<<t.val<<endl;
		vec.pb(t);
	}
	for(int i=vec.size()-1;i>1;i-=2)
	{
		if(vec[i].val>vec[i-1].val)
		{
			vec[i/2]=vec[i];
		}
		else
		{
			vec[i/2]=vec[i-1];
		}
	}
	char ch;
	foi(m)
	{
		cin>>ch;
		//foj(vec.size())cout<<vec[j].val<<" ";
		//cout<<endl;
		if(ch=='R')
		{
			cin>>var>>ver;
			int ps = len+var-1;
			vec[ps].val=ver;
			if(ps%2==0)ps+=1;
			while(ps>1)
			{
				if(vec[ps].val>=vec[ps-1].val)
				{
					vec[ps/2]=vec[ps];
					ps/=2;
				}
				else 
				{
					vec[ps/2]=vec[ps-1];
					ps/=2;
				}
				if(ps%2==0)ps+=1;
			}

		}
		else if(ch=='W')
		{
			cout<<vec[1].pos<<endl;
		}
		else
		{
			cin>>var;
			int ps = var+len-1;
			tour curr = vec[ps];
			int ans = 0;
			while(vec[ps/2]==curr&&ps>1)
			{
				ans++;
				ps/=2;
			}
			cout<<ans<<endl;
		}
	}
}