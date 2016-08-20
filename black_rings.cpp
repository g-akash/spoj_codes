#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		vector<int> R,r;
		cin>>n;
		R.resize(n);
		r.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>r[i]>>R[i];
		}
		int maxind=0;
		for(int i=1;i<n;i++)
		{
			if(r[i]>r[maxind])maxind=i;
		}
		int ansind=maxind;
		for(int i=0;i<n;i++)
		{
			if(i==maxind)continue;
			if(R[i]>=r[maxind])ansind=-2;
		}
		cout<<ansind+1<<endl;
	}
}