#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,e;
		cin>>n>>e;
		vector<vector<int> > v;
		vector<int> visited;
		v.resize(n);
		visited.resize(n);
		int a,b;
		for(int i=0;i<e;i++)
		{
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ans=0;
		for(int j=0;j<n;j++)
		{
			int c,d;
			if(visited[j])continue;
			stack<int> s;
			ans++;
			//visited[i]=1;
			s.push(j);
			while(!s.empty())
			{
				c=s.top();
				s.pop();
				visited[c]=1;
				for(int k=0;k<v[c].size();k++)
				{
					if(!visited[v[c][k]])s.push(v[c][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
} 
		
			
		
