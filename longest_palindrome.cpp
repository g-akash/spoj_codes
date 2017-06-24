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
	cin>>n;
	string s;
	cin>>s;
	//cout<<n<<s<<endl;
	int ans=0;
	string str_ans="";
	for(int i=0;i<n-1;i++)
	{
		int x,y,ans1=0,ans2=0;
		string str_ans1,str_ans2;
		//i is in the middle
		ans1=1;
		x=i-1;y=i+1;
		while(x>=0&&y<n)
		{
			if(s[x]==s[y])ans1+=2;
			else break;
			x--;
			y++;
			//cout<<x<<" "<<y<<" "<<ans1<<endl;
		}
		x++;
		y--;
		str_ans1 = s.substr(x,y-x+1);
		//i,i+1 are the middle
		x=i;
		y=i+1;
		ans2=0;
		while(x>=0&&y<n)
		{
			if(s[x]==s[y])ans2+=2;
			else break;
			x--;
			y++;
		}
		//cout<<ans1<<" anss "<<ans2<<endl;
		x++;
		y--;
		str_ans2 = s.substr(x,y-x+1);
		if(ans1>ans){ans=ans1;str_ans=str_ans1;}
		if(ans2>ans){ans=ans2;str_ans=str_ans2;}
	}
	cout<<ans<<endl;
	cout<<str_ans<<endl;
}