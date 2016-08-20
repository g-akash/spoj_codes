#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class activity
{
	public:
	int start,end;
};

bool comp(activity p, activity q)
{
	if(p.end<q.end)return true;
	if(p.end==q.end&&p.start<=q.start)return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	vector<activity> v;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		
		v.resize(n);
		for(int j=0;j<n;j++)cin>>v[j].start>>v[j].end;
		sort(v.begin(),v.end(),comp);
	int ans=0,currend=0;
	for(int j=0;j<n;j++)
	{
		if(v[j].start>=currend){ans++;currend=v[j].end;}

	}
	cout<<ans<<endl;
	}
}