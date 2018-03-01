#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

int n,m;

bool isDisconnected(vector<umm(int,int) > &vec)
{
	vector<int> visited(n+1);
	stack<int> st;
	st.push(1);
	int count=0;
	int curr;
	while(!st.empty())
	{
		curr=st.top();
		st.pop();
		if(visited[curr])continue;
		visited[curr]=1;
		count+=1;
		umm(int,int)::iterator it = vec[curr].begin();
		while(it!=vec[curr].end())
		{
			if(!visited[it->first])
			st.push(it->first);
			it++;
		}
	}
	//cout<<count<<endl;
	return count!=n;
}

int main()

{
	
	cin>>n>>m;
	vi st(m),ed(m),count(n+1);
	foi(n+1)count[i]=0;
	foi(m)
	{
		cin>>st[i]>>ed[i];
		count[st[i]]+=1;
		count[ed[i]]+=1;
	}
	bool isEuler = true;
	foi1(n)if(count[i]%2==1){isEuler=false;break;}else count[i]/=2;
	if(!isEuler)
	{
		cout<<"NO"<<endl;
		//cout<<"prob"<<endl;
		return 0;
	}
	vector<unordered_map<int,int> > vec(n+1);
	vector<unordered_map<int,int> > fr(n+1);
	vector<unordered_map<int,int> > bk(n+1);
	foi(m)
	{
		vec[st[i]][ed[i]]+=1;
		vec[ed[i]][st[i]]+=1;
		fr[st[i]][ed[i]]=1;
		bk[ed[i]][st[i]]=1;
	}
	if(isDisconnected(vec))
	{
		cout<<"NO"<<endl;
		return 0;
	}
	int done_edges = 0;
	int curr = 1;
	vector<umm(int,int) > fin_ans(n+1);
	bool isans=true;
	int sst = 1;
	curr=sst;
	while(done_edges!=m)
	{
		//cout<<done_edges<<" "<<curr<<endl;
		if(fr[curr].begin()!=fr[curr].end())
		{
			int nex = (fr[curr].begin())->first;
			done_edges+=1;
			bk[nex].erase(curr);
			fr[curr].erase(nex);
			fin_ans[curr][nex]+=1;
			curr=nex;
		}
		else if(bk[curr].begin()!=bk[curr].end())
		{
			int nex = (bk[curr].begin())->first;
			done_edges+=1;
			bk[curr].erase(nex);
			fr[nex].erase(curr);
			fin_ans[curr][nex]+=1;
			curr=nex;
		}
		else
		{
			for(int i=sst+1;i<=n;i++)
			{
				if(fr[i].size()!=0||bk[i].size()!=0)
				{
					sst=i;
					curr=sst;
					break;
				}
			}
		}
	}
	if(!isans)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	
	//foi1(n)count[i]=int(vec[i].size())/2;
	curr = 1;
	
	
	
	
	
	
	
	
	
	
	
	//~ while(count[curr]>0)
	//~ {
		//~ //cout<<curr<<count[curr]<<endl;
		//~ unordered_map<int,int>::iterator it;
		//~ it = vec[curr].begin();
		//~ //if(it==vec[curr].end())break;
		//~ int nex = it->first;
		//~ vec[nex][curr]-=1;
		//~ vec[curr][nex]-=1;
		//~ if(vec[nex][curr]==0)vec[nex].erase(curr);
		//~ if(vec[curr][nex]==0)vec[curr].erase(nex);
		//~ fin_ans[curr][nex]+=1;
		//~ count[curr]-=1;
		//~ curr=nex;
		//~ //cout<<curr<<"     "<<count[curr]<<endl;
	//~ }
	cout<<"YES"<<endl;
	foi(m)
	{
		
		if(fin_ans[st[i]].find(ed[i])==fin_ans[st[i]].end())
		{
			cout<<ed[i]<<" "<<st[i]<<endl;
			fin_ans[ed[i]][st[i]]-=1;
			if(fin_ans[ed[i]][st[i]]==0)fin_ans[ed[i]].erase(st[i]);
		}
		else 
		{
			cout<<st[i]<<" "<<ed[i]<<endl;
			fin_ans[st[i]][ed[i]]-=1;
			if(fin_ans[st[i]][ed[i]]==0)fin_ans[st[i]].erase(ed[i]);
		}
	}
	
	
	
}
