#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ull  long long int

int main()
{
	int t;
	cin>>t;
	for(ull i=0;i<t;i++)
	{
		ull n;
		cin>>n;
		bool cando = true;
		vector<ull> v;
		v.resize(n);
		for(ull j=0;j<n;j++){cin>>v[j];}
		sort(v.begin(),v.end());
		ull ans=0;
		
		
			ans=1;
			for(ull j=0;j<n;j++)
			{
				if(v[j]<j+1)cando=false;
				ans*=(v[j]-j);
				ans%=1000000007;
			}
		
		if(cando)
		cout<<ans<<endl;
		else cout<<0<<endl;

	}
	cout<<"KILL BATMAN"<<endl;
}