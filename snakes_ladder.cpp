#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <queue>


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


class ps
{
public:
	int cpos,mov;
};

int main()
{
	int t,a,b;
	cin>>t;
	foi(t)
	{
		unordered_map<int,int> snak,ladd;
		int m;
		cin>>m;
		foj(m)
		{
			cin>>a>>b;
			ladd[a]=b;
		}
		cin>>m;
		foj(m)
		{
			cin>>a>>b;
			snak[a]=b;
		}
		
		vi vis(101);
		queue<ps> q;
		ps crr,vr;
		crr.cpos=1;
		crr.mov=0;
		q.push(crr);
		vis[1]=0;
		while(!q.empty())
		{
			if(q.front().cpos==100)
			{
				vis[100]=1;
				break;
			}
			crr=q.front();
			q.pop();
			if(vis[crr.cpos])continue;
			//cout<<crr.cpos<<endl;
			vis[crr.cpos]=1;
			int a,b=crr.mov+1;
			a=crr.cpos+1;
			if(snak.find(a)!=snak.end())a=snak[a];
			else if(ladd.find(a)!=ladd.end())a=ladd[a];
			vr.cpos=a;
			vr.mov=b;
			q.push(vr);

			a=crr.cpos+2;
			if(snak.find(a)!=snak.end())a=snak[a];
			else if(ladd.find(a)!=ladd.end())a=ladd[a];
			vr.cpos=a;
			vr.mov=b;
			q.push(vr);

			a=crr.cpos+3;
			if(snak.find(a)!=snak.end())a=snak[a];
			else if(ladd.find(a)!=ladd.end())a=ladd[a];
			vr.cpos=a;
			vr.mov=b;
			q.push(vr);

			a=crr.cpos+4;
			if(snak.find(a)!=snak.end())a=snak[a];
			else if(ladd.find(a)!=ladd.end())a=ladd[a];
			vr.cpos=a;
			vr.mov=b;
			q.push(vr);

			a=crr.cpos+5;
			if(snak.find(a)!=snak.end())a=snak[a];
			else if(ladd.find(a)!=ladd.end())a=ladd[a];
			vr.cpos=a;
			vr.mov=b;
			q.push(vr);

			a=crr.cpos+6;
			if(snak.find(a)!=snak.end())a=snak[a];
			else if(ladd.find(a)!=ladd.end())a=ladd[a];
			vr.cpos=a;
			vr.mov=b;
			q.push(vr);

		}
		if(vis[100]==1)
		{
			cout<<q.front().mov<<endl;
		}
		else cout<<-1<<endl;
	}
}