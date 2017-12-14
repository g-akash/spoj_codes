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

//aabbabbaabab
// vector<char> construct_string(int n)
// {
// 	vector<char> ans(n);
// 	ans[0]='a';
// 	ans[1]='a';
// 	ans[2]='a';
// 	ans[3]='b';
// 	ans[4]='a';
// 	ans[5]='b';
// 	ans[6]='b';
// 	n-=7;
// 	int pos = 7;
// 	while(n!=0)
// 	{

// 	}
// }

int main()
{
	string s="aaababbb";
	string s1 = "aabbab";
	//cout<<"kk"<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		int n,r;
		cin>>n>>r;
		if(r==1)
		{
			cout<<n<<" ";
			foi(n)cout<<'a';
			cout<<endl;
		}
		else if(r==2)
		{
			if(n<=1)cout<<1<<" "<<'a'<<endl;
			else if(n==2)cout<<1<<" "<<"ab"<<endl;
			else if(n==3)cout<<2<<" "<<"aab"<<endl;
			else if(n==4)cout<<2<<" "<<"aabb"<<endl;
			else if(n<=8)cout<<3<<" "<<s.substr(0,n)<<endl;
			else 
			{
				cout<<4<<" ";
				while(n>=6)
					{
						cout<<s1;
						n-=6;
					}
					cout<<s1.substr(0,n)<<endl;
			}
			
		}
		else
		{
			int curr=0;
			cout<<1<<" ";
			while(n>0)
			{
				cout<<char(curr+97);
				curr=(curr+1)%r;
				n-=1;
			}
			cout<<endl;
		}
	}

}