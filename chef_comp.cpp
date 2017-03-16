#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

vector<int> v;
vector<int> s;


void comp(int x, int y)
{
	int v1=v[x],v2=v[y];
	//cout<<v1<<" "<<v2<<"aks"<<endl;
	if(v1==v2)cout<<"Invalid query!"<<endl;
	else if(s[x]>s[y])v[y]=v1;
	else v[x]=v2;
	return;
}


int main()
{
	int t;
	scanf("%u",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%u",&n);
		v.resize(n+1);
		s.resize(n+1);
		for(int j=1;j<=n;j++){v[j]=j;cin>>s[j];}
		int q;
		cin>>q;
		int var,x,y;
		for(int j=0;j<q;j++)
		{
			scanf("%u",&var);
			if(var==0){scanf("%u",&x);scanf("%u",&y);comp(x,y);}
			else {scanf("%u",&x);printf("%u\n",v[x]);}
		}
	}
}
