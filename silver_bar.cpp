#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		int ans=1,currl=1,var=1;
		while(currl<n){currl+=2*var;var*=2;ans++;}
		
		cout<<ans-1<<endl;
		cin>>n;
	}
}