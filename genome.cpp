#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


int main()
{
	int n,a=0,g=0,c=0,t=0;
	string s;
	cin>>n>>s;
	foi(s.length())
	{
		if(s[i]=='A')a++;
		else if(s[i]=='G')g++;
		else if(s[i]=='C')c++;
		else if(s[i]=='T')t++;
	}
	if(n%4!=0||a>n/4||g>n/4||c>n/4||t>n/4)
	{
		cout<<"==="<<endl;
		return 0;
	}
	string ans="";
	a=n/4-a;
	g=n/4-g;
	c=n/4-c;
	t=n/4-t;
	foi(n)
	{
		if(s[i]!='?')ans+=s.substr(i,1);
		else if(a>0){ans+="A";a--;}
		else if(g>0){ans+="G";g--;}
		else if(c>0){ans+="C";c--;}
		else {ans+="T";t--;}
	}
	cout<<ans<<endl;


}