#include<iostream>
#include<math.h>
#include<set>
#include<vector>
#include<unordered_set>

#define ull unsigned long long int

using namespace std;
vector<ull> v;

ull ansi(ull n)
{
	set<ull> s;
	ull ans=0;
	for(ull i=0;i<n-1;i++)s.insert(v[i]);
	for(ull i=n-1;i<v.size();i++)
	{
		s.insert(v[i]);
		ans+=*s.rbegin();
		s.erase(v[i-(n-1)]);
	}
	return ans;
}


int main()
{
	ull n;
	cin>>n;
	v.resize(n);
	for(ull i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(ull i=1;i<=n;i++)
	{
		cout<<ansi(i)<<endl;
	}
	
}