#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

class ston
{
public:
	int weg,count;

	ston()
	{
		weg=0;
		count=0;
	}
};

bool comp(ston p, ston q)
{
	if(p.count<q.count)return true;
	else if(p.count==q.count&&p.weg<q.weg)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,var;
		cin>>n;
		vi ank(101),rup(101);
		foi(n)
		{
			cin>>var;
			rup[var]++;
		}
		foi(n)
		{
			cin>>var;
			ank[var]++;
		}
		vector<ston> an,ru;
		ston st;
		foi(101)
		{
			if(rup[i]>0)
			{
				st.count=rup[i];
				st.weg=i;
				ru.pb(st);
			}
		}
		foi(101)
		{
			if(ank[i]>0)
			{
				st.count=ank[i];
				st.weg=i;
				an.pb(st);
			}
		}

		sort(an.begin(),an.end(),comp);
		sort(ru.begin(),ru.end(),comp);
		if(an[an.size()-1].weg>ru[ru.size()-1].weg)cout<<"Ankit"<<endl;
		else if(an[an.size()-1].weg<ru[ru.size()-1].weg)cout<<"Rupam"<<endl;
		else cout<<"Tie"<<endl;

	}
}