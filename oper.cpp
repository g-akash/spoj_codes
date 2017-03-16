#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

class nod
{
public:
	int val,l,r;
};

vector<vector<nod> > v;


void add(int x)
{
	int  j=x,ad;
	if(v[17][j].val==1)ad=0;
	else ad=1;
	for(int i=17;i>=0;i--)
	{
		v[i][j].val+=ad;
		j/=2;
	}
	return;
}

void delet(int x)
{
	int j=x;
	for(int i=17;i>=0;i--)
	{
		v[i][j].val-=1;
		j/=2;
	}
	return;
}

int reportrank(int i, int j, int curr, int x)
{
	
	if(i==17)return curr+1;
	//cout<<i<<" "<<curr<<" "<<v[i+1][2*j].r<<endl;
	if(x>v[i+1][2*j].r)
	{
		curr+=v[i+1][2*j].val;
		return reportrank(i+1,2*j+1,curr,x);
	}
	return reportrank(i+1,2*j,curr,x);
}

int reportkth(int i, int j, int k)
{
	if(i==17)return j;
	if(k>v[i+1][2*j].val)
	{
		k-=v[i+1][2*j].val;
		return reportkth(i+1,2*j+1,k);
	}
	return reportkth(i+1,2*j,k);
}



void maketree()
{
	v.resize(18);
	v[0].resize(1);
	v[0][0].val=0;
	for(int i=1;i<18;i++)
	{
		v[i].resize(v[i-1].size()*2);
		//for(int j=0;j<v[i].size();j++)v[i][j].val=0;
	}
	for(int j=0;j<v[17].size();j++)
	{
		v[17][j].l=j;
		v[17][j].r=j;
		v[17][j].val=0;
	}
	for(int i=16;i>=0;i--)
	{
		for(int j=0;j<v[i].size();j++)
		{
			v[i][j].l=v[i+1][2*j].l;
			v[i][j].r=v[i+1][2*j+1].r;
			v[i][j].val=0;
		}
	}
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		maketree();
		int q;
		cin>>q;
		for(int j=0;j<q;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			//cin>>a>>b;
			if(a==1)
			{
				add(b);
			}
			else if(a==2)
			{
				delet(b);
			}
			else if(a==3)
			{
				cout<<reportkth(0,0,b)<<endl;
			}
			else 
				cout<<reportrank(0,0,0,b)<<endl;
	//	prnt();
		}

	}

}