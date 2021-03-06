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


void update(int i,int j,int k)
{
	if(i<0)return;
	seg[i][j].val+=k;
	update(i-1,j/2,k);
	return;
}


int query(int i, int j,int x,int y)
{
	
	if(i>seg[x][y].r)return 0;
	if(j<seg[x][y].l)return 0;
	if(i==seg[x][y].l&&j==seg[x][y].r)return seg[x][y].val;
	if(i>seg[x+1][2*y].r)return query(i,j,x+1,2*y+1);
	if(j<seg[x+1][2*y+1].l)return query(i,j,x+1,2*y);
	return query(i,seg[x+1][2*y].r,x+1,2*y)+query(seg[x+1][2*y+1].l,j,x+1,2*y+1);

}


int main()
{
	for(int ko=0;ko<10;ko++){
	int n;
	cin>>n;
	vector<int> v;
	v.resize(n);
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')v[i]=1;
			else v[i]=-1;
		
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
		seg[seg.size()-1][i].val=v[i];
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
			seg[i][j].val=seg[i+1][2*j].val+seg[i+1][2*j+1].val;
		}
	}
	int q,a,b;
	cin>>q;
	cout<<"Test "<<ko+1<<":"<<endl;
	for(int i=0;i<q;i++)
	{
		scanf("%d",&a);
		if(a==0){
		if(seg[0][0].val==0)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;}
	else{
		if(seg[seg.size()-1][a-1].val==1)b=-2;
		else b=2;
		update(seg.size()-1,a-1,b);
		}
	}
}
	
}

