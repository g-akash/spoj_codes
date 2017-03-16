#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>

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


ll gcd(int x, int y)
{
	if(x%y==0)return y;
	return gcd(y,x%y);
}

class queu
{
public:
	ll st,pos;

	bool operator <(const queu& q) const
	{
		if(this->st<q.st)return true;
		if(this->st==q.st&&this->pos<q.pos)return true;
		return false;
	}
};

bool comp(queu p, queu q)
{
	if(p.st<q.st)return true;
	if(p.st==q.st&&p.pos<q.pos)return true;
	return false;
}

vector<queu> v;

int main()
{
	int n;
	cin>>n;
	queu q;
	foi(n)
	{
		ll cnt=0;
		ll x1,x2,y1,y2,x,y;
		cin>>x1>>y1>>x2>>y2;
		x=abs(x2-x1);y=abs(y2-y1);
		//cout<<x1<<x2<<y1<<y2<<endl;
		//cout<<x<<" xy "<<y<<endl;
		if(x==0)
		{
			cnt=y+1;
		}
		else if(y==0)
		{
			cnt=x+1;
		}
		else
		{
			ll gd = gcd(x,y);
			cnt=(gd)+1;
		}
		
		q.st=cnt;
		q.pos=i+1;
		v.pb(q);
	}
	sort(v.begin(),v.end(),comp);
	//foi(v.size())cout<<v[i].st<<" "<<v[i].pos<<endl;
	cin>>n;
	ll var;
	foi(n)
	{
		vector<queu>::iterator it;
		cin>>var;
		q.st=var;
		q.pos=-1;
		it=upper_bound(v.begin(),v.end(),q);
		if(it!=v.end())
		{
			cout<<it->pos<<endl;
		}
		else cout<<-1<<endl;
	}

}