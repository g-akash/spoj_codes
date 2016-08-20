#include <bits/stdc++.h>

using namespace std;

vector<int> parent,sizes;
int n,m,q;

int getroot(int a)
{
	if(parent[a]==a)return a;
	int x=getroot(parent[a]);
	parent[a]=x;
	return x;
}

void merge(int a, int b)
{
	int x=getroot(a);
	int y=getroot(b);
	if(x!=y)
	{
		if(sizes[x]+sizes[y]<=m)
		{
			parent[x]=y;
			sizes[y]+=sizes[x];
		}
	}
	return;
}


int main()
{
	cin>>n>>m>>q;
	parent.resize(n+1);
	sizes.resize(n+1);
	for(int i=0;i<=n;i++)
	{
		parent[i]=i;
		sizes[i]=1;
	}
	string s;

	int a,b;
	for(int i=0;i<q;i++)
	{
		cin>>s;
		if(s=="A")
		{
			cin>>a>>b;
			merge(a,b);
		}
		else if(s=="E")
		{
			cin>>a>>b;
			if(getroot(a)==getroot(b))
			{
				cout<<"Yes"<<endl;
			}
			else
				cout<<"No"<<endl;
		}
		else
		{
			cin>>a;
			cout<<sizes[getroot(a)]<<endl;
		}
	}
}