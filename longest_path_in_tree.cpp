#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

vector<vector<int> > v;
vector<int> visited;


vector<int> doit(int x)
{
	//cout<<x<<endl;
	visited[x]=1;
	int strt1=0,strt2=0,len=0,finstrt=0;
	vector<int> temp;
	temp.resize(2);
	for(int i=0;i<v[x].size();i++)
	{
		if(visited[v[x][i]])continue;
		temp=doit(v[x][i]);
		len=max(len,temp[1]);
		if(temp[0]+1>strt2){strt1=strt2;strt2=temp[0]+1;}
		else if(temp[0]+1>strt1){strt1=temp[0]+1;}
		finstrt=max(finstrt,1+temp[0]);
	}
	len=max(len,strt1+strt2);
	temp[0]=finstrt;
	temp[1]=len;
	return temp;
}

int main()
{
	int t;
	cin>>t;
	for(int ko=0;ko<t;ko++){
	int n;
	cin>>n;
	visited.clear();
	visited.resize(n+1);
	int a,b;
	v.clear();
	v.resize(n+1);
	vector<int> ans;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans=doit(1);
	if(ans[1]%2==0)cout<<ans[1]/2<<endl;
	else cout<<(ans[1]+1)/2<<endl;
	//cout<<ans[1]<<endl;
}
}
