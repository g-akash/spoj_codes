#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long int 

int main()
{
	unordered_map<ull,ull> m;
	bool ans=true;
	ull var;
	cin>>var;
	while(var>1&&m.find(var)==m.end())
	{
		m[var]=1;
		if(var%2==0)var/=2;
		else var=3*var+3;
		
	}
	if(m.find(var)!=m.end())
	{
		cout<<"NIE"<<endl;
	}
	else cout<<"TAK"<<endl;
}