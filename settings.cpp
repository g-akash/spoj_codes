#include<iostream>
#include<set>
#include<math.h>

using namespace std;


int main()
{
	int t;
	cin>>t;
	int a,b;
	set<int> m;
	int n=1;
	while(!(n>100000000)){m.insert(n);n*=2;}
	for(int i=0;i<t;i++)
	{
		int ans=0;
		cin>>a>>b;
		while(!(a<=b&&m.find(a)!=m.end()))
		{
			
			a/=2;
			ans++;
		}
		while(a!=b){a*=2;ans++;}
		cout<<ans<<endl;
	}
}
		
