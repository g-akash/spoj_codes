#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,j;
		cin>>n;
		int w1,maxh=-10000;
		vector<int> wei,hor;
		wei.resize(n-1);
		hor.resize(n);
		cin>>w1;
		for(j=0;j<n-1;j++)cin>>wei[j];
		for(j=0;j<n;j++){cin>>hor[j];maxh=max(maxh,hor[j]);}
		for(j=0;j<n;j++)if(hor[j]==maxh)break;
		hor.erase(hor.begin()+j,hor.begin()+j+1);
		sort(hor.begin(),hor.end());
		sort(wei.begin(),wei.end());
		for(j=0;j<n-1;j++){if(hor[j]*wei[n-2-j]>=w1*maxh){cout<<"No"<<endl;break;}}
		if(j>=n-1)cout<<"Yes"<<endl;
	}
}
