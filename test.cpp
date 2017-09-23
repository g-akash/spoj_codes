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
#include <iomanip>

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

double inc[1000000][10];

int main()
{
	
	foi(9)inc[0][i]=1.0;
	inc[0][9]=9;
	bool cont=true;
	foi1(1000000-1)
	{
		inc[i][0]=inc[i-1][0];
		//cout<<inc[i][0]<<" ";
		foj1(9)
		{
			inc[i][j]=inc[i][j-1]+inc[i-1][j];
			// if(inc[i][j]<0)
			// {
			// 	cout<<i<<" "<<j<<endl;
			// 	cont = false;
			// 	break;
			// }
			//cout<<inc[i][j]<<" ";
		}
		if(!cont)break;
		//cout<<endl;
	}
	//cout<<inc[2][9]<<" "<<inc[2][8]<<endl;
	//cout<<inc[999999][9]<<" "<<inc[999999][8]<<endl;
	//cout<<fixed<<setprecision(8)<<inc[999999][9]/inc[999999][8]<<endl;
	//cout<<inc[99999][9]<<endl;
	foi(100)
	{	cout<<inc[i][9]<<" "<<inc[i][8]<<" ";
		cout<<(inc[i][9])/inc[i][8]<<endl;
	}
}