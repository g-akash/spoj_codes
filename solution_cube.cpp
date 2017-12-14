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
int c[6][8];

bool solved()
{
	if(c[0][2]==c[0][3]&&c[1][2]==c[1][3]&&c[0][2]==c[1][2])
	{
		if(c[2][2]==c[2][3]&&c[3][2]==c[3][3]&&c[2][2]==c[3][2])
		{
			if(c[4][2]==c[4][3]&&c[5][2]==c[5][3]&&c[4][2]==c[5][2])
				if(c[2][0]==c[2][1]&&c[3][0]==c[3][1]&&c[2][0]==c[3][0])
					if(c[2][4]==c[2][5]&&c[3][4]==c[3][5]&&c[2][4]==c[3][4])
						if(c[2][6]==c[2][7]&&c[3][6]==c[3][7]&&c[2][6]==c[3][6])
						{
							cout<<"YES"<<endl;
							return true;
						}
		}
		
	}
	return false;
}

void rot_r()
{
	int a = c[2][0],b=c[2][1];
	c[2][0]=c[2][2];c[2][1]=c[2][3];
	c[2][2]=c[2][4];c[2][3]=c[2][5];
	c[2][4]=c[2][6];c[2][5]=c[2][7];
	c[2][6]=a;c[2][7]=b;
	return;
}

void rot_l()
{
	int a = c[2][0],b=c[2][1];
	c[2][0]=c[2][6];c[2][1]=c[2][7];
	c[2][6]=c[2][4];c[2][7]=c[2][5];
	c[2][4]=c[2][2];c[2][5]=c[2][3];
	c[2][2]=a;c[2][3]=b;
	return;
}

void rot_sr()
{
	int a = c[0][3], b = c[1][3];
	c[0][3]=c[2][3];c[1][3]=c[3][3];
	c[2][3]=c[4][3];c[3][3]=c[5][3];
	c[4][3]=c[3][6];c[5][3]=c[2][6];
	c[3][6]=a;c[2][6]=b;
	return;
}

void rot_sl()
{
	int a = c[0][3], b = c[1][3];
	c[0][3]=c[3][6];c[1][3]=c[2][6];
	c[3][6]=c[4][3];c[2][6]=c[5][3];
	c[4][3]=c[2][3];c[5][3]=c[3][3];
	c[2][3]=a;c[3][3]=b;
		
	return;	
}

void rot_tr()
{
	int a=c[1][2],b=c[1][3];
	c[1][2]=c[2][4];c[1][3]=c[3][4];
	c[2][4]=c[4][3];c[3][4]=c[4][2];
	c[4][3]=c[3][1];c[4][2]=c[2][1];
	c[3][1]=a;c[2][1]=b;
	return;
}

void rot_tl()
{
	int a=c[1][2],b=c[1][3];
	c[1][2]=c[3][1];c[1][3]=c[2][1];
	c[3][1]=c[4][3];c[2][1]=c[4][2];
	c[4][3]=c[2][4];c[4][2]=c[3][4];
	c[2][4]=a;c[3][4]=b;
	return;	
}

void printit()
{
	foi(6)
	{
		foj(8)
		cout<<c[i][j]<<" ";
	cout<<endl;
	}
	return;
}


int main()
{
	
	foi(6)
	{
		cin>>c[i][2]>>c[i][3];
	}
	cin>>c[2][0]>>c[2][1];
	cin>>c[3][0]>>c[3][1];
	cin>>c[2][4]>>c[2][5];
	cin>>c[3][4]>>c[3][5];
	cin>>c[2][6]>>c[2][7];
	cin>>c[3][6]>>c[3][7];
	rot_r();
	if(solved())return 0;
	rot_l();
	rot_l();
	if(solved())return 0;
	rot_r();
	rot_tr();
	if(solved())return 0;
	rot_tl();
	rot_tl();
	if(solved())return 0;
	rot_tr();
	rot_sr();
	if(solved())return 0;
	rot_sl();
	rot_sl();
	if(solved())return 0;
	cout<<"NO"<<endl;
	return 0;
}