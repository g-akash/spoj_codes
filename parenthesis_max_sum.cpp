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


ll n;
vi vec;
vi sums;


void make_array_sum()
{
	sums.resize(n);
	sums[0]=vec[0];
	for(ll i=1;i<n;i++)
	{
		sums[i]=sums[i-1]+vec[i];
	}
	return;
}


ll get_sum(ll a,ll b)
{
	if(a==0)return sums[b];
	return sums[b]-sums[a-1];
}

class balan
{
public:
	ll a;
	ll b;
	balan()
	{

	}
	balan(ll x, ll y)
	{
		a=x;
		b=y;
	}
};


bool balanced(char ch, char ed)
{
	if(ch=='('&&ed==')')return true;
	else if(ch=='{'&&ed=='}')return true;
	else if(ch=='['&&ed==']')return true;
	else if(ch=='<'&&ed=='>')return true;
	return false;
}



int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string s;
		cin>>s;
		vec.resize(n);
		foi(n)cin>>vec[i];
		make_array_sum();
		stack<char> st;
		stack<ll> nums;
		vector<balan> balans;
		for(ll i=0;i<s.length();i++)
		{
			if(st.empty())
			{
				st.push(s[i]);
				nums.push(i);
			}
			else
			{
				if(balanced(st.top(),s[i]))
				{
					st.pop();
					balan bln(nums.top(),i);
					balans.pb(bln);
					nums.pop();

				}
				else
				{
					st.push(s[i]);
					nums.push(i);
				}
			}
		}
		ll curr_sum = 0;
		for(ll i=0;i<balans.size();i++)
		{
			curr_sum = max(curr_sum,get_sum(balans[i].a,balans[i].b));
		}
		cout<<curr_sum<<endl;
	}
}