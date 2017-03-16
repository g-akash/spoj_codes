#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class event
{
	public:
	int time,eve;
};

bool comp(event p, event q)
{
	if(p.time<q.time)return true;
	if(p.time==q.time&&p.eve==-1)return true;
	return false;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<event> v;
		int var;
		for(int j=0;j<n;j++)
		{
			event e;
			cin>>var;
			e.time=var;e.eve=+1;
			v.push_back(e);
			cin>>var;
			e.time=var;
			e.eve=-1;
			v.push_back(e);
		}
		sort(v.begin(),v.end(),comp);
		int maxx=0;
		var=0;
		for(int j=0;j<2*n;j++)
		{
			var+=v[j].eve;
			if(var>maxx)maxx=var;
		}
		cout<<maxx<<endl;
	}
}
		
