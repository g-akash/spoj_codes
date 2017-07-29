#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
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
	char ch;
	cin>>n;
	cin.get(ch);
	vector<string> vec;
	string lin;
	foi(n)
	{
		getline(cin,lin);
		vec.pb(lin);
	}
	vector<string> ans;
	string var="";
	foi(n)
	{
		var="";
		foj(vec[i].length())
		{
			ch=vec[i][j];
			if(ch==' '||ch==','||ch=='.'||ch==';'||ch==':')
			{
				if(var!="")
				{
					ans.pb(var);
					var="";
				}
			}
			else
			{
				var=var+string(1,tolower(vec[i][j]));
			}
		}
		if(var!="")ans.pb(var);
	}
	
	sort(ans.begin(),ans.end());
	int count=1;
	foi1(ans.size()-1)if(ans[i]!=ans[i-1])count++;
	cout<<count<<endl;
	cout<<ans[0]<<endl;
	foi1(ans.size()-1)if(ans[i]!=ans[i-1])cout<<ans[i]<<endl;
}