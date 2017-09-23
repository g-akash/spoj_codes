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

int p,n;
vi facts;



int power(int a, int b)
{
	ll var = (ll)a;
	ll ans = 1;
	while(b!=0)
	{
		if(b%2==1)ans=ans*var;
		ans=ans%p;
		var=var*var;
		var%=p;
		b/=2;
	}
	return (int)ans;
}


void get_facts()
{
	int num = p-1;
	int srt = (int)sqrt(num);
	for(int i=2;i<=srt;i++)
	{
		if(num%i==0)
		{
			facts.pb(i);
			facts.pb(num/i);
		}
	}
	return;
}


int main()
{
	
	while(cin>>p>>n)
	{
		facts.resize(0);
		get_facts();
		// foi(facts.size())cout<<facts[i]<<" ";
		// cout<<endl;
		foi(n)
		{
			int num;
			cin>>num;
			bool ans = true;
			foj(facts.size())
			{
				if(power(num,facts[j])==1)
				{
					ans=false;
					break;
				}
			}
			if(ans)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}