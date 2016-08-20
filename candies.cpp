#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		unsigned long long int cand=0,a,maxx=0;
		for(int j=0;j<n;j++)
		{
			cin>>a;
			cand+=a;
			maxx=max(a,maxx);
		}
		cout<<maxx*n-cand<<endl;
	}
	
}
