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
		string s1;
		cin>>s1;
		ull a=int(s1[s1.length()-1])-48,b,ans=1;
		cin>>b;
		vector<int> v;
		v.resize(64);
		v[0]=a;
		for(int j=1;j<64;j++)v[j]=(v[j-1]*v[j-1])%10;
			int k=0;
		while(b>0){if(b&0x1){ans*=v[k];};b=b>>1;k++;ans=ans%10;}
		cout<<ans<<endl;
	}
}