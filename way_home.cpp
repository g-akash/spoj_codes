#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[1025][1025];

void  fill(int x, int y)
{
	if(a[x][y]>=0)return;
	
	if(x<=0||y<=0)return;
	if(a[x-1][y]<0)fill(x-1,y);
	if(a[x][y-1]<0)fill(x,y-1);
	if(a[x-1][y-1]<0)fill(x-1,y-1);
	a[x][y]=((a[x-1][y]+a[x][y-1])%1000000007+a[x-1][y-1])%1000000007;
	//cout<<x<<" "<<y<<" "<<a[x][y]<<endl;
	return;

}

int main()
{

	for(int i=0;i<1025;i++)
	{
		for(int j=0;j<1025;j++)a[i][j]=-1;
	}
a[1][1]=1;
for(int i=0;i<1025;i++){a[0][i]=0;a[i][0]=0;}
	fill(1024,1024);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int x,y,c,d;
		cin>>x>>y>>c>>d;
		cout<<a[c-x+1][d-y+1]<<endl;
	}

}