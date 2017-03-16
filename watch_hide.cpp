#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


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


int dh,dm;
int get_dig(int x)
{
	int ans=0;
	while(x!=0)
	{
		//cout<<x<<endl;
		ans++;
		x/=7;
	}
	//cout<<ans<<endl;
	return max(ans,1);
}

bool is_displayable(int x, int y)
{
	//cout<<x<<" "<<y<<endl;
	string s1="",s2="";
	foi(dm){
		s2=to_string(y%7)+s2;
		y/=7;
		//cout<<y<<endl;
	}
	foi(dh){
		s1=to_string(x%7)+s1;
		x/=7;
	}
	//cout<<s1<<" "+s2<<endl;
	s1+=s2;
	vector<char> vec(dh+dm);
	foi(s1.length())vec[i]=s1[i];
	sort(vec.begin(),vec.end());
	for(int i=1;i<vec.size();i++)if(vec[i]==vec[i-1])return false;
	//cout<<s1<<endl;
	return true;
}

int main()
{
	int n,m;
	cin>>n>>m;
	dh=get_dig(n-1);dm=get_dig(m-1);
	if(dh+dm>7)
	{
		cout<<0<<endl;
	}
	else{
		int ans=0;
		foi(n){
			foj(m){
				if(is_displayable(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
}