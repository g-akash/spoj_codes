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
		ull n,k,ans=0,var;
		cin>>n>>k;
		var=n/k;
		ans+=(var*k*(k-1))/2;
		var=n%k;
		ans+=(var*(var+1))/2;
		cout<<ans<<endl;

	}
}