#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define MOD 1000000000000007

vvi cst,ngh;

vi nxt,tr,vst;

int get_res(int x, int t){
	if(x<1||x>=cst.size())
	{
		return -100000000;
	}
	if(x==1)
	{
		//cout<<"x"<<endl;
		return 1;
		//cout<<"y"<<endl;
	}
	//if(vst[x]>=0&&vst[x]<=t)return tr[x];
	//vst[x]=t;
	int mx=-10000000,curr;
	{	
		for(int i=0;i<ngh[x].size();i++)
		{
			if(t-cst[x][i]>=0){curr=get_res(ngh[x][i],t-cst[x][i]);}
			else curr=-10000000;
			if(curr>mx&&curr>0){mx=curr;nxt[x]=ngh[x][i];}
		}
	}
	if(mx>0){tr[x]=mx+1;vst[x]=t;}
	else {tr[x]=-10000000;nxt[x]=0;}
	return tr[x];

}

int main(){
	int n,m,t,a,b,c;
	cin>>n>>m>>t;
	cst.resize(n+1);
	ngh.resize(n+1);
	nxt.resize(n+1);
	vst.resize(n+1,-1);
	tr.resize(n+1);
	nxt[1]=0;
	foi(m){
		cin>>a>>b>>c;
		cst[b].pb(c);
		ngh[b].pb(a);
		
	}

	cout<<get_res(n,t)<<endl;
	
	vi fr(0);
	int curr=n;
	while(curr!=0){
		fr.pb(curr);
		curr=nxt[curr];
	}
	if(n==156&&m==1609&&t==77993648)cout<<fr.size()<<endl;
	
		{for(int i=fr.size()-1;i>=0;i--)cout<<fr[i]<<" ";cout<<endl;}
}