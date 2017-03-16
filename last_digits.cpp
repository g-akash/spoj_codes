#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ull unsigned long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<ull> v;
		ull a,b;
		v.resize(40);
		cin>>a>>b;
		v[0]=a%10;
		for(int j=1;j<40;j++)
			v[j]=(v[j-1]*v[j-1])%10;
		ull ans=1,k=0;
		for(k=0;k<40;k++)
		{
			if(b&0x1)
			ans*=(v[k]*(b&0x1));
			ans=ans%10;
			b=b>>1;
		}
		cout<<ans<<endl;

	}
}