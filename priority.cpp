#include <iostream>
#include <queue>

using namespace std;
#define ll long long int


int main()
{
	priority_queue<ll> q;
	ll n;
	ll a,b,c,var,ans;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>var;
		q.push(var);
		a=q.top();
		q.pop();
		if(!q.empty()){b=q.top();q.pop();}
		else b=-1;
		if(!q.empty()){c=q.top();q.pop();ans=a*b*c;}
		else {ans=-1;c=-1;}
		cout<<ans<<endl;
		q.push(a);
		if(b!=-1)q.push(b);
		if(c!=-1)q.push(c);

	}
}