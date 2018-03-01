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

string s;
int c0 = 0;


int main()
{
	
	cin>>s;
	ll ans = 0;
	vll zs(s.length());
	if(int(s[0])%8==0)ans+=1;
	if(s.length()<=1)
	{
		cout<<ans<<endl;
		return 0;
	}
	if(int(s[0])==48)zs[0]=1;
	if(int(s[1])%8==0)ans+=(ll)1;
	if(s[0]!='0'&&((int(s[0])-48)*10+(int(s[1])-48))%8==0)ans+=(ll)1;
	//cout<<(int(s[0])-48)*10+(int(s[1])-48)<<endl;
	if(s.length()<=2)
	{
		cout<<ans<<endl;
		return 0;
	}
	if(int(s[1])==48)zs[1]=zs[0]+1;
	else zs[1]=zs[0];
	for(int i=2;i<s.length();i++)
	{
		string tmp = s.substr(i-2,3);
		//cout<<tmp<<endl;
		//cout<<stoi(tmp)<<endl;
		if(stoi(tmp)%8==0)
		{
			if(tmp[0]!='0')ans+=1;
			if(i-3>=0)
			{
				ans+=(ll)(i-2-zs[i-3]);
			}
		}
		if(stoi(tmp.substr(1,2))%8==0&&tmp[1]!='0')ans+=(ll)1;
		if(int(tmp[2])%8==0)ans+=(ll)1;
		if(tmp[2]=='0')zs[i]=zs[i-1]+1;
		else zs[i]=zs[i-1];

	}cout<<ans<<endl;

}