#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int

class robot
{
public:
	ll p,m;
};


bool comp(robot p, robot q)
{
	//defines when p is less than q
	if(p.p<q.p)return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll n,tot;
		cin>>n>>tot;
		vector<robot> robots;
		robots.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>robots[j].p>>robots[j].m;
		}
		sort(robots.begin(),robots.end(),comp);
		ll minan=robots[0].m,minp=robots[0].p;
		int k=1;
		while(k<n)
		{
			if((robots[k].p-minp)*minan<=tot){tot-=((robots[k].p-minp)*minan);minan+=robots[k].m;minp=robots[k].p;}
			else
			{
				ll var=tot/minan;
				minp+=(var);
				tot-=(var*minan);
				break;
			}
			k++;
		}
		minp+=(tot/minan);
		cout<<minp<<endl;
	}
}