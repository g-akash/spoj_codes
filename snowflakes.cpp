#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


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


class node{
public:
	int nodes,parent,centroid,maxnodes;
	vector<int> nex;
	node(){
		nodes=-1;
		maxnodes=0;
		centroid=-1;
	}
};

vector<node> vec;
int n,q,var;
int calc_child(int x)
{
	int tot_child=0;
	foi(vec[x].nex.size()){
		if(vec[vec[x].nex[i]].nodes==-1)tot_child+=calc_child(vec[x].nex[i]);
		else tot_child+=vec[vec[x].nex[i]].nodes;
		vec[x].maxnodes=max(vec[x].maxnodes,vec[vec[x].nex[i]].nodes);
	}
	tot_child+=1;
	vec[x].nodes=tot_child;
	return tot_child;
}

bool is_centroid(int x, int y)
{
	int var = vec[x].nodes-vec[y].nodes;
	if(var*2>vec[x].nodes)return false;
	int maxn=vec[y].maxnodes;
	if(maxn*2>vec[x].nodes)return false;
	return true;
}

int calc_centroid(int x)
{
	if(vec[x].nex.size()==0)
	{
		vec[x].centroid=x;
		return x;
	}
	int nods=0,cent=x;
	foi(vec[x].nex.size()){
		if(vec[vec[x].nex[i]].centroid<0)calc_centroid(vec[x].nex[i]);
		if(vec[vec[x].nex[i]].nodes>nods){
			nods=vec[vec[x].nex[i]].nodes;
			cent=vec[x].nex[i];
		}
	}
	cent=vec[cent].centroid;
	while(!is_centroid(x,cent)&&cent!=1)cent=vec[cent].parent;
	//do some calculation
	vec[x].centroid=cent;
	return cent;
}

int main()
{
	
	//cin>>n>>q;
	scanf("%d",&n);
	scanf("%d",&q);
	vec.resize(n+1);
	foi(n-1){
		//cin>>var;
		scanf("%d",&var);
		vec[var].nex.pb(i+2);
		vec[i+2].parent=var;
	}
	calc_child(1);
	calc_centroid(1);
	foi(q){
		//cin>>var;
		scanf("%d",&var);
		//cout<<vec[var].centroid<<endl;
		printf("%d\n",vec[var].centroid);
	}
}