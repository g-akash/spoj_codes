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
	int n,q,var,pos;
	cin>>n>>q;
	string s;
	cin>>s;
	char ch[n+1],c;
	vi vec(26);
	foi1(n)
	{
		ch[i]=s[i-1];
		vec[int(s[i-1])-65]++;
	}
	//foj(26)cout<<vec[j]<<" ";cout<<endl;
	foi(q)
	{
		cin>>var>>pos;
		if(var==1)
		{
			cin>>c;
			vec[int(ch[pos])-65]--;
			vec[int(c)-65]++;
			ch[pos]=c;
		}
		else
		{
			int temp=0;
			foj(26)
			{
				if(temp+vec[j]>=pos){
					cout<<char(j+65)<<endl;
					break;
				}
				temp+=vec[j];
			}
		}
	}
	//foj(26)cout<<vec[j]<<" ";cout<<endl;
}