#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <stdio.h>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int n,m,q,a,b;
vvi mat,sm;
vector<mm(int,int) > maps(1005);
mm(int,int) mp;

void make_sums()
{
	sm[0][0]=mat[0][0];
	foi1(m-1)
	{
		sm[0][i]=sm[0][i-1]+mat[0][i];
	}
	foi1(n-1)
	{
		sm[i][0]=sm[i-1][0]+mat[i][0];
	}
	foi1(n-1)
	{
		foj1(m-1)
		{
			sm[i][j]=sm[i][j-1]+sm[i-1][j]-sm[i-1][j-1]+mat[i][j];
		}
	}
	return;
}

int get_sum(int x1, int y1, int x2, int y2)
{
	//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	if(x1<=0&&y1<=0)return sm[x2][y2];
	if(x1<=0)return sm[x2][y2]-sm[x2][y1-1];
	if(y1<=0)return sm[x2][y2]-sm[x1-1][y2];
	return sm[x2][y2]-sm[x1-1][y2]-sm[x2][y1-1]+sm[x1-1][y1-1];

}

int get_array_mx(int x)
{
	if(x<0)return 0;
	mm(int,int)::iterator it = maps[x].end();
	it--;
	return it->first;

}

void remove_array_mx(int x, int val)
{
	if(x<0)return;
	int vl = maps[x][val];
	if(vl>1)maps[x][val]-=1;
	else
	{
		maps[x].erase(val);
	}
	return;

}

void remove_mx(int val)
{
	int vl = mp[val];
	if(vl>1)mp[val]-=1;
	else mp.erase(val);
	return;
}


int get_val(int x, int y)
{
	if(x<0||y<0)return 0;
	return mat[x][y];
}

void add_mx(int val)
{
	mp[val]+=1;
}

void make_base(int x, int y)
{
	foi(1005)maps[i]= *(new map<int,int>);
	foi(a-1)
	{
		foj(m)
		{
			maps[j][mat[i][j]]+=1;
		}
	}
}

void make_summ(int x)
{
	if(x-a>=0)
	{
		for(int i=0;i<b-1;i++)
		{
			int vl = maps[i][mat[x-a][i]];
			if(vl>1)maps[i][mat[x-a][i]]-=1;
			else	
				maps[i].erase(mat[x-a][i]);

		}
	}
	mp = *(new map<int,int>);
	mm(int,int)::iterator it;
	for(int i=0;i<b-1;i++)
	{
		maps[i][mat[x][i]]+=1;
		it = maps[i].end();
		it--;
		mp[it->first]+=1;

	}
	return;
	


}


int get_mx()
{
	mm(int,int)::iterator it = mp.end();
	it--;
	return it->first;
}

int main()
{
	scanf("%d %d",&n,&m);
	mat.resize(n);
	sm.resize(n);
	foi(n){mat[i].resize(m);sm[i].resize(m);}
	foi(n)
	{
		foj(m)scanf("%d",&mat[i][j]);
	}
	make_sums();
	scanf("%d",&q);
	while(q--)
	{
		int ans = 1000000000;
		scanf("%d %d",&a,&b);
		make_base(a,b);
		for(int i=a-1;i<n;i++)
		{
			make_summ(i);
			for(int j=b-1;j<m;j++)
			{
				int mx = get_array_mx(j-b);
				remove_mx(mx);
				remove_array_mx(j,get_val(i-a,j));
				maps[j][mat[i][j]]+=1;
				//if(j==2)cout<<maps[j][mat[i][j]]<<" vll "<<mat[i][j]<<endl;
				mx = get_array_mx(j);
				add_mx(mx);
				mx = get_mx();
				//cout<<mx<<"-";
				int sm = get_sum(i-a+1,j-b+1,i,j);
				//cout<<sm<<"-";
				ans = min(ans,mx*(a*b)-sm);
				//cout<<ans<<" ";

			}
			//cout<<endl;
		}
		printf("%d\n",ans);
	}

}