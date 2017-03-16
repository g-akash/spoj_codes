#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>


#define ull unsigned long long int

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull n,ans,m,var;
		var=1;
		cin>>n;
		var+=(30*n)%11;
		var+=32%11;
		var%=11;
		if(var>0)
		cout<<11-var<<endl;
		else cout<<0<<endl;
	}
}