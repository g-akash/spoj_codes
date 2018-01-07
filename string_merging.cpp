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

int t;
int n,m;
int voc[5005][5005];
char s1[5005], s2[5005];


int get_ans(int x, int y)
{
	
	if(x>=n||y>=m){return 0;}
	
	if(voc[x][y]!=-1)return voc[x][y];
	int ans=0;
	if(s1[x]==s2[y])
	{
		ans = get_ans(x+1,y+1)+1;
		voc[x][y]=ans;
		return ans;
	}
	else
	{
		ans = max(get_ans(x+1,y),get_ans(x,y+1));
		voc[x][y]=ans;
		return ans;
	}
	
}

int main()
{
	
	scanf("%d",&t);
	

	while(t--)
	{
		
		scanf("%d %d",&n,&m);
		scanf("%s %s",s1,s2);
		foi(n)
		{
			foj(m)voc[i][j]=-1;
		}
		int curr = 1;
		for(int i=1;i<n;i++)
		{
			if(s1[i]!=s1[i-1])
			{
				s1[curr]=s1[i];
				curr+=1;
			}

		}
		n = curr;
		curr=1;
		for(int i=1;i<m;i++)
		{
			if(s2[i]!=s2[i-1])
			{
				s2[curr]=s2[i];
				curr+=1;
			}
		}
		m = curr;
		//cout<<n<<" "<<m<<endl;
		int ls = get_ans(0,0);
		printf("%d\n",n+m-ls);//<<endl;
	}

}