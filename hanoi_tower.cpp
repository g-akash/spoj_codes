#include<iostream>
#include<math.h>

using namespace std;

#define ull unsigned long long int

int main()
{
	cout<<(pow(3,35))<<endl;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull var,ans;
		cin>>var;

		ans=(ull)pow(3,var);
		ans=ans-1;
		cout<<ans<<endl;
	}
}