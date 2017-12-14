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



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll a=0,b=0;
		ll x,y;
		cin>>x>>y;
		foi(s.length())
		{
			if(s[i]=='a')a++;
			else if(s[i]=='b')b++;
		}
		bool reverse=false;
		if(b>a)
		{
			b+=a;
			a=b-a;
			b=b-a;
			y+=x;
			x=y-x;
			y=y-x;
			reverse=true;
		}
		if((b+1)*x>=a)
		{
			ll norm = a/(b+1);
			ll lef = a-(b+1)*norm;
			char ch1='a',ch2='b';
			if(reverse)
			{
				ch1='b';
				ch2='a';
			}
			for(ll i=0;i<b+1;i++)
			{
				cout<<string(norm,ch1);
				if(lef>0)
				{
					cout<<ch1;
					lef-=1;
				}
				if(i<b)cout<<ch2;
			}
			cout<<endl;
		}
		else
		{	
			ll left = a-(b+1)*x;
			char ch1='a',ch2='b';
			if(reverse)
			{
				ch1='b';
				ch2='a';
			}
			cout<<string(x,ch1);
			foi(left)cout<<"*"<<ch1;
			foi(b)
			{
				cout<<ch2<<string(x,ch1);
			}
			cout<<endl;

		}

	}
}