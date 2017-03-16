#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

//unordered_map<string,int> m;

int a[2001][2001];
string s1,s2;

int dist(int x, int y)
{
	if(x==0&&y==0)
	{
		a[x][y]=0;return 0;
	}
	else if(x==0&&y!=0)
	{
		a[x][y]=y;
		return y;
	}
	else if(y==0)
	{
		a[x][y]=x;
		return x;
	}
	else if(a[x][y]>=0)
	{
		return a[x][y];
	}
	else if(s1[x-1]==s2[y-1])
	{
		a[x][y]=dist(x-1,y-1);
		return a[x][y];
		}
	else
	{
		int m,n,o,p;
		m=dist(x-1,y)+1;
		n=dist(x,y-1)+1;
		o=dist(x-1,y-1)+1;
		p=min(m,min(n,o));
		a[x][y]=p;
		return p;
	}
}

int main()

{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<2001;j++)for(int k=0;k<2001;k++)a[j][k]=-1;
		
		cin>>s1>>s2;
		cout<<dist(s1.length(),s2.length())<<endl;
	}
}
	
