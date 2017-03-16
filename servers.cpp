#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()

class tsk
{
public:
	int tim,serv,typ,num;
};

bool comp(tsk p, tsk q)
{
	if(p.tim<q.tim)return true;
	if(p.tim==q.tim && p.typ==2&&q.typ==1)return true;
	return false;
}


int main()
{
	int n,q,a,b,c;
	cin>>n>>q;
	vector<tsk> tasks;
	tsk ts;
	foi(q)
	{
		cin>>a>>b>>c;
		ts.serv=b;
		ts.tim=a;
		ts.typ=1;
		ts.num=i+1;
		tasks.pb(ts);
		ts.tim=a+c;
		ts.typ=2;
		tasks.pb(ts);
	}
	vi taken(q+1),ms(n+1);
	sort(tasks.begin(),tasks.end(),comp);
	int ans=0,cs=n,sum=0;
	foi(tasks.size())
	{
		if(tasks[i].typ==1)
		{
			if(cs>=tasks[i].serv)
			{
				cs-=tasks[i].serv;
				ans=0;
				taken[tasks[i].num]=1;
				sum=0;
				for(int j=1;j<=n&&ans<tasks[i].serv;j++)
				{
					if(ms[j]==0)
					{
						ms[j]=tasks[i].num;
						ans++;
						sum+=j;
					}
				}
				cout<<sum<<endl;

			}
			else cout<<-1<<endl;
		}
		else
		{
			if(taken[tasks[i].num]==1)
			cs+=tasks[i].serv;
			for(int j=1;j<=n;j++)if(ms[j]==tasks[i].num)ms[j]=0;
		}
	}
	//cout<<ans<<endl;

}