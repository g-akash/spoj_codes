#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define ll long long int

int main()
{
	int n;
	multiset<ll> m;
	map<ll,ll> mp;
	cin>>n;
	ll var;
	string s;
	multiset<ll>::iterator it;
	int count=0;
	for(ll i=0;i<n;i++)
	{
		cin>>s;
		cin>>var;
		if(s=="insert"){m.insert(var);mp[var]++;if(mp[var]==2)count++;}
		else if(s=="delete"){it=m.find(var);if(it!=m.end()){mp[*it]--;if(mp[*it]==1)count--;m.erase(it);}}
		bool nei=false,homo=false,hetro=false;
		it=m.begin();
		if(it==m.end()||++it==m.end()){nei=true;goto result;}
		it=m.end();
		it--;
		if(*it!=*(m.begin()))hetro=true;
		if(count>0)homo=true;
		result:
		if(nei==true)cout<<"neither\n";
		else if(homo==true&&hetro==false)cout<<"homo\n";
		else if(homo==false&&hetro==true)cout<<"hetero\n";
		else cout<<"both\n";
	}
}