#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	int n;
	string s;
	cin>>n;
	int ans=0;
	foi(n)
	{
		cin>>s;
		if(s=="Tetrahedron")ans+=4;
		else if(s=="Cube")ans+=6;
		else if(s=="Octahedron")ans+=8;
		else if(s=="Dodecahedron")ans+=12;
		else if(s=="Icosahedron")ans+=20;
	}
	cout<<ans<<endl;
}