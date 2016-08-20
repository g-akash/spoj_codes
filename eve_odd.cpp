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

void prnt()
{
	for(int i=0;i<seg.size();i++)
	{
		for(int j=0;j<seg[i].size();j++)
			cout<<seg[i][j].val;
		cout<<endl;
	}
	cout<<endl;
}

void update(int i,int j)
{
	if(i<0)return;
	int val1,val2;
	val1=seg[i+1][2*j].val;val2=seg[i+1][2*j+1].val;
	int l1=seg[i+1][2*j+1].l,r1=seg[i+1][2*j+1].r;
	if((r1+1-l1)%2==1){seg[i][j].val=(val1*2+val2)%3;}
	else seg[i][j].val=(val1+val2)%3;
	update(i-1,j/2);
	return;
}


int query(int i, int j,int x,int y)
{
	
	if(i>seg[x][y].r)return 0;
	if(j<seg[x][y].l)return 0;
	if(i==seg[x][y].l&&j==seg[x][y].r)return seg[x][y].val;
	if(i>seg[x+1][2*y].r)return query(i,j,x+1,2*y+1);
	if(j<seg[x+1][2*y+1].l)return query(i,j,x+1,2*y);
	return (query(i,seg[x+1][2*y].r,x+1,2*y)*(1+(j+1-seg[x+1][2*y+1].l)%2)+query(seg[x+1][2*y+1].l,j,x+1,2*y+1))%3;

}


int main()
{
	
	int n;
	cin>>n;
	vector<int> v;
	v.resize(n);
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')v[i]=0;
		else v[i]=1;
		
	}
	int var=1,cnt=1;
	while(var<n){var*=2;cnt++;}
	
	seg.resize(cnt);
	seg[0].resize(1);
	for(int i=1;i<seg.size();i++)
	{
		seg[i].resize(seg[i-1].size()*2);
	}

	for(int i=0;i<n;i++)
	{
		seg[seg.size()-1][i].l=i;
		//cout<<i<<endl;
		seg[seg.size()-1][i].r=i;
		seg[seg.size()-1][i].val=v[i]%2;
	}
	for(int i=n;i<seg[seg.size()-1].size();i++)
	{
		seg[seg.size()-1][i].l=i;
		seg[seg.size()-1][i].r=i;
		seg[seg.size()-1][i].val=0;
	}
	


	for(int i=seg.size()-2;i>=0;i--)
	{
		for(int j=0;j<seg[i].size();j++)
		{
		//	cout<<i<<" "<<j<<" yes"<<endl;
			seg[i][j].l=seg[i+1][2*j].l;
			seg[i][j].r=seg[i+1][2*j+1].r;
			seg[i][j].val=(seg[i+1][2*j].val*((1+(1+seg[i+1][2*j+1].r-seg[i+1][2*j+1].l)%2))+seg[i+1][2*j+1].val)%3;
		}
	}
	int q,a,b,c,k;
	cin>>q;
	//cout<<"Test "<<ko+1<<":"<<endl;
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;

		if(a==0)
		{
			cin>>c;
			cout<<query(b,c,0,0)<<endl;
			

		}
		else if(a==1)
		{
			
			if(seg[seg.size()-1][b].val==0)seg[seg.size()-1][b].val=1;

			update(seg.size()-2,b/2);
		}
		//prnt();
		
	}
}
	


