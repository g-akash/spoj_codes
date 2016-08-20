#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		vector<int> sta,trip;
		sta.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>sta[i];
		}
		sort(sta.begin(),sta.end());
		for(int i=0;i<sta.size();i++)
		{
			trip.push_back(sta[i]);
		}
		for(int i=sta.size()-1;i>=0;i--)
		{
			trip.push_back(sta[i]);
		}
		int curr=-200;
		bool ans=true;
		for(int i=0;i<trip.size()/2;i++)
		{
			if(abs(trip[i]-curr)>200){ans=false;}
			curr=trip[i];
		}
		if(curr!=1422)curr+=2*abs(1422-curr);
		for(int i=trip.size()/2;i<trip.size();i++)
		{
			if(abs(trip[i]-curr)>200){ans=false;}
			curr=trip[i];	
		}
		if(ans!=0&&ans>200)ans=false;
		if(ans)cout<<"POSSIBLE"<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
		cin>>n;
	}
}