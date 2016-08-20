#include<iostream>
#include<vector>

using namespace std;

#define ull unsigned long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull n,cut=0,len=1,ans;
		cin>>n;
		while(len<n)len*=2;
		ans=len;
		while(n>0)
		{
			if(len<=n){n-=(len);}
			else{len/=2;cut++;}
			
		}
		cout<<ans<<" "<<cut<<endl;
	}
}