#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		unsigned long long int n;
		cin>>n;
		int ans = int(log2(n))+1;
		cout<<ans<<endl;
	}
}
