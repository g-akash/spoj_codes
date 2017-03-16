#include <iostream>
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


class oper
{
public:
	ll t,r,c,x;
};

int main()
{
	ll n,m,q,temp;
	cin>>n>>m>>q;
	vector<vector<ll> > vec(n);
	foi(n)vec[i].resize(m);
	foi(n)foj(m)vec[i][j]=100000000000;
	vector<oper> op(q);
	foi(q)
	{
		cin>>op[i].t;
		if(op[i].t==1)cin>>op[i].r;
		else if(op[i].t==2)cin>>op[i].c;
		else if(op[i].t==3)cin>>op[i].r>>op[i].c>>op[i].x;
		op[i].r--;
		op[i].c--;
	}
	for(int i=q-1;i>=0;i--)
	{
		//cout<<op[i].t<<endl;
		if(op[i].t==1)
		{
			temp=vec[op[i].r][m-1];
			for(int j=m-1;j>=1;j--)vec[op[i].r][j]=vec[op[i].r][j-1];
			vec[op[i].r][0]=temp;
		}
		else if(op[i].t==2)
		{
			temp=vec[n-1][op[i].c];
			for(int j=n-1;j>=1;j--)vec[j][op[i].c]=vec[j-1][op[i].c];
			vec[0][op[i].c]=temp;
		}
		else 
		{
			//cout<<"kk"<<endl;
			vec[op[i].r][op[i].c]=op[i].x;
			//cout<<"xx"<<endl;
		}
	}
	foi(n)foj(m)if(vec[i][j]==100000000000)vec[i][j]=0;
	foi(n){foj(m)cout<<vec[i][j]<<" ";cout<<endl;}
}