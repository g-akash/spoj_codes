#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> p,q,pp,qp;
vector<vector<int> > np;
bool con(vector<int> p, vector<int> q)
{
	int var;
	vector<int> vis1,vis2,p1;
	vis1.resize(p.size());
	p1.resize(p.size());
	vis2.resize(q.size());
	for(int i=0;i<p.size();i++)
	{
		if(vis1[i]==1)continue;
		stack<int> s;
		s.push(i);
		while(!s.empty())
		{
			var=s.top();
			s.pop();
			vis1[var]=1;
			p1[var]=i;
			for(int j=0;j<np[var].size();j++)
				if(vis1[np[var][j]]!=1)s.push(np[var][j]);
		}
	}
	for(int i=0;i<p.size();i++)
	{
		pp[p[i]]=p1[i];
		qp[q[i]]=p1[i];
	}
	
	if(pp==qp)return true;
	else return false;
}


int main()
{
	int t,a,b;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		int n,m;
		cin>>n>>m;
		
		p.resize(n);
		q.resize(n);
		pp.resize(n);qp.resize(n);
		np.resize(n);
		for(int i=0;i<n;i++){cin>>p[i];p[i]-=1;np[i].resize(0);}
		for(int i=0;i<n;i++){cin>>q[i];q[i]-=1;}
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			a--;
			b--;
			np[a].push_back(b);
			np[b].push_back(a);
		}

		if(con(p,q))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}