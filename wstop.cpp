#include<iostream>
#include<unordered_map>

using namespace std;

#define ll long long int
unordered_map<ll,int> m;

int main()
{
	long long int n;
	cin>>n;
	bool ans=true;
	while(n>1)
	{
		if(m.find(n)!=m.end()){ans=false;break;}
		m[n]=1;
		if(n%2==0)n/=2;
		else n=3*n+3;
	}
	if(n==1)cout<<"TAK"<<endl;
	else cout<<"NIE"<<endl;
}