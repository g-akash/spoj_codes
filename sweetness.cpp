#include<iostream>
#include<vector>
#include<set>

using namespace std;

#define ll long long int

int main()
{
	ll n,k,var,v;
	cin>>n>>k;
	multiset<ll> s;
	for(int i=0;i<n;i++)
	{
		cin>>var;
		s.insert(var);
	}
	int count=0;
	while(*s.begin()<k)
	{
		if(s.begin()==s.end()){cout<<-1<<endl;return 0;}
		var=*(s.begin());
		s.erase(s.begin());
		if(s.begin()==s.end()){cout<<-1<<endl;return 0;}
		v=*(s.begin());
		s.erase(s.begin());
		
		//cout<<var<<" "<<v<<" ";
		var=var+2*v;
		//cout<<var<<endl;
		s.insert(var);
		count++;
	}
	cout<<count<<endl;
}
