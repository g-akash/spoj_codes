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
#include <time.h>

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


int n;
string s1,s2;
vll v1,v2;
vll sh1,sh2;

ll get_hsh(int a, int b)
{
	if(a==0)return sh2[b];
	else return (sh2[b]-sh2[a-1])-(v1[b-a]*(ll)(a));
}

bool check(int a, int b)
{

	if(sh1[b]!=get_hsh(a,a+b))return false;
	if(b==0)return true;
	int x;
	x = rand()%b;
	if(sh1[x]!=get_hsh(a,a+x))return false;
	x=rand()%b;
	if(sh1[x]!=get_hsh(a,a+x))return false;
	x = rand()%b;
	if(sh1[x]!=get_hsh(a,a+x))return false;
	x = rand()%b;
	if(sh1[x]!=get_hsh(a,a+x))return false;
	x = rand()%b;
	if(sh1[x]!=get_hsh(a,a+x))return false;
	x = rand()%b;
	if(sh1[x]!=get_hsh(a,a+x))return false;

	//cout<<"returning true"<<a<<" "<<b<<endl;
	return true;
}

ll get_vhsh(int a, int b)
{
	if(a==0)return v2[b];
	return v2[b]-v2[a-1];
}

bool final_check(int a, int b)
{
	// foi(b+1)
	// {
	// 	if(s1[i]!=s2[a+i])return false;
	// }
	return true;
}


int lngst(int x)
{
	int x1=0,x2=n-1,y1=x,y2=x+n-1;
	while(true)
	{
		int mid = (x1+x2)/2;
		if(v1[mid]==get_vhsh(x,x+mid))
		{
			x1=mid;
		}
		else
		{
			x2=mid;
		}
		if(x2-x1<=1)
		{
			
			if(check(x,x2)){if(final_check(x,x2))return x2+1;}
			if(check(x,x1)){if(final_check(x,x1))return x1+1;}
			if(x1==0)return 0;
			else{x1=0,x2=x2-1;}
		}
	}
}


int main()
{
	srand(time(NULL));
	cin>>n;
	cin>>s1>>s2;
	s2+=s2;
	v1.resize(s1.length());
	sh1.resize(s1.length());
	v2.resize(s2.length());
	sh2.resize(s2.length());
	v1[0]=(int)s1[0];
	sh1[0]=(int)s1[0];
	foi1(s1.length()-1)
	{
		sh1[i]=sh1[i-1]+(ll)(i+1)*(ll)s1[i];
		v1[i]=v1[i-1]+(ll)s1[i];
	}
	v2[0]=(int)s2[0];
	sh2[0]=(int)s2[0];
	foi1(s2.length()-1)
	{
		sh2[i]=sh2[i-1]+(ll)(i+1)*(ll)s2[i];
		v2[i]=v2[i-1]+(ll)s2[i];
	}
	//foi(v1.size())cout<<v1[i]<<" ";cout<<endl;
	//foi(v2.size())cout<<v2[i]<<" ";cout<<endl;
	int ans = 0,shft=0;
	foi(n+1)
	{
		//cout<<i<<" calling"<<endl;
		int var = lngst(i);
		//cout<<i<<" "<<var<<endl;
		if(var>ans)
		{
			ans=var;
			shft=i;
		}
		if(ans==n)break;
	}
	cout<<shft<<endl;

}