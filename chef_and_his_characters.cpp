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



int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		vi vec(26);
		if(s.length()<4)
		{
			cout<<"normal"<<endl;
			continue;
		}
		vec[int(s[0])-97]+=1;
		vec[int(s[1])-97]+=1;
		vec[int(s[2])-97]+=1;
		int ans = 0;
		for(int i=3;i<s.length();i++)
		{
			vec[int(s[i])-97]+=1;
			if(vec['c'-97]==1&&vec['h'-97]==1&&vec['e'-97]==1&&vec['f'-97]==1)ans+=1;
			vec[s[i-3]-97]-=1;
		}
		if(ans>0)
		{
			cout<<"lovely "<<ans<<endl;
		}
		else cout<<"normal"<<endl;
	}
}