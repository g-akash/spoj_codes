#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	vector<vector<int> > events;
	int n,q;
	cin>>n>>q;
	vector<int> app;
	events.resize(n+1);
	int rd=0,pos=0,ans=0;
	int typ,var;

	for(int i=0;i<q;i++)
	{
		cin>>typ>>var;
		if(typ==1)
		{
			app.push_back(var);
			events[var].push_back(app.size()-1);
			ans++;
			cout<<ans<<endl;
		}
		else if(typ==2)
		{
			for(int j=0;j<events[var].size();j++)
			{
				if(app[events[var][j]]!=0){app[events[var][j]]=0;ans--;}
			}
			events[var].resize(0);
			cout<<ans<<endl;
		}

		else if(typ==3)
		{
			if(var>rd)
			{
				for(int j=0;j<var-rd;j++)
				{
					if(app[pos]!=0){ans--;app[pos]=0;}
					pos++;
				}
				rd=var;
			}
			cout<<ans<<endl;
		}
	}
}