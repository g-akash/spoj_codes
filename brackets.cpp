#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;


class nod
{
public:
	int l,r,val;
};

vector<vector<nod> > seg;

int query(int i, int j,int a, int b)
{
	//cout<<i<<" "<<j<<endl;
	//cout<<seg[i][j].l<<" "<<seg[i][j].r<<endl;
	if(i>=seg.size()||j>=seg[i].size())return 0;
	if(seg[i][j].l==a&&seg[i][j].r==b)return seg[i][j].val;
	if(seg[i+1][2*j].r<a)return query(i+1,2*j+1,a,b);
	if(seg[i+1][2*j+1].l<b)return query(i+1,2*j,a,b);
	return query(i+1,2*j,a,seg[i+1][2*j].r)+query(i+1,2*j+1,seg[i+1][2*j+1].l,b);
}


void update(int i, int j, int vll)
{

	if(i<0)return;
	if(j>=seg[i].size())return;
	seg[i][j].val+=vll;
	update(i-1,j/2,vll);
}


void maketree(char s[],int len)
{
	int lev=1,ln=1;
	while(ln<len)
	{
		lev++;
		ln*=2;
	}
	seg.resize(lev);
	seg[0].resize(1);
	for(int i=1;i<seg.size();i++)
	{
		seg[i].resize(seg[i-1].size()*2);
	}
	lev--;
	for(int i=0;i<len;i++)
	{
		seg[lev][i].l=i;
		seg[lev][i].r=i;
		if(s[i]=='(')seg[lev][i].val=-1;
			else seg[lev][i].val=1;
	}
	for(int i=len;i<seg[lev].size();i++)
	{
		seg[lev][i].val=0;
		seg[lev][i].l=i;
		seg[lev][i].r=i;
	}
	for(int i=lev-1;i>=0;i--)
	{
		for(int j=0;j<seg[i].size();j++)
		{
			seg[i][j].val=seg[i+1][2*j].val+seg[i+1][2*j+1].val;
			seg[i][j].l=seg[i+1][2*j].l;seg[i][j].r=seg[i+1][2*j+1].r;
		}
	}
	return;

}

int main()

{
	int n,q,var,vll;
	for(int i=0;i<10;i++)
	{
		
		cin>>n;
		char s[n];
		scanf("%s",s);
		maketree(s,n);
		cin>>q;
		cout<<"Test "<<i+1<<":"<<endl;
		for(int j=0;j<q;j++)
		{
			scanf("%d",&var);
			if(var==0)
			{
				if(query(0,0,0,n-1)==0)printf("YES\n");
				else printf("NO\n");
			}
			else
			{
				if(seg[seg.size()-1][var-1].val==1)vll=-2;
				else vll=+2;
				update(seg.size()-1,var-1,vll);
			}
		}
	}
}