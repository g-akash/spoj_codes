#include<iostream>
#include<algorithm>
#include<map>

using namespace std;


#define ull unsigned long long int

ull happiness(ull n)
{
	ull ans=0;
	while(n!=0)
	{
		ans+=((n%10)*(n%10));
		n/=10;
	}
	return ans;
}

int main()
{
	ull n,ans=0;
	map<ull,ull> m;
	cin>>n;
	while(n!=1&&m.find(n)==m.end())
	{
		m[n]=1;
		n=happiness(n);
		ans++;
	}
	if(m.find(n)!=m.end())
	{
		cout<<-1<<endl;
	}
	else cout<<ans<<endl;
}