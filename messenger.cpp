#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define MOD 1000000000000007

int has(string s)
{
	ll ans=1;
	foi(s.length()){
		ans*=(ll)(s[i]);
		ans%=MOD;
	}
	return ans;
}


int main(){
	int n,m,ans=0;
	cin>>n>>m;
	vector<string> str,pt;
	string tmp;
	cin>>tmp;
	str.pb(tmp);
	for(int i=1;i<n;i++)
		{
			cin>>tmp;
			int x=str.size()-1;
			int y=str[x].length()-1;
			if(tmp[tmp.length()-1]==str[x][y])
			{
				y=stoi(tmp.substr(0,tmp.find("-")))+stoi(str[x].substr(0,str[x].find("-")));
				str[x]=to_string(y)+"-"+tmp.substr(tmp.length()-1,1);
			}
			else str.pb(tmp);
		}
	cin>>tmp;
	pt.pb(tmp);
	for(int i=1;i<m;i++)
		{
			cin>>tmp;
			int x=pt.size()-1;
			int y=pt[x].length()-1;
			if(tmp[tmp.length()-1]==pt[x][y])
			{
				y=stoi(tmp.substr(0,tmp.find("-")))+stoi(pt[x].substr(0,pt[x].find("-")));
				pt[x]=to_string(y)+"-"+tmp.substr(tmp.length()-1,1);
			}
			else pt.pb(tmp);
		}
		//foi(pt.size())cout<<pt[i]<<endl;
		m=pt.size();
		n=str.size();
	if(m==1){
		foi(n){
			if(pt[0].substr(pt[0].find("-")+1)==str[i].substr(str[i].find("-")+1))
			{
				int x=stoi(pt[0].substr(0,pt[0].find("-"))),y=stoi(str[i].substr(0,str[i].find("-")));
				if(y>=x)ans+=(y-x+1);

			}
		}
	}
	else if(m==2){
		foi(n-1){
			//committing an error here
			if(pt[0].substr(pt[0].find("-")+1)==str[i].substr(str[i].find("-")+1)&&pt[1].substr(pt[1].find("-")+1)==str[i+1].substr(str[i+1].find("-")+1))
			{
				int x=stoi(pt[0].substr(0,pt[0].find("-"))),y=stoi(str[i].substr(0,str[i].find("-"))),a=stoi(pt[1].substr(0,pt[1].find("-"))),b=stoi(str[i+1].substr(0,str[i+1].find("-")));
				if(y>=x&&b>=a)ans+=(1);

			}
		}
	}
	else
	{
		ll hsh=0;
		foi1(m-2){
			hsh+=has(pt[i]);
			hsh%=MOD;
		}
		ll var=0;
		vi pose,poss;
		for(int i=0;i<m-2;i++)
		{
			var+=has(str[i]);
		}
		for(int i=m-2;i<n-1;i++){
			var+=has(str[i]);
			var-=has(str[i+2-m]);
			while(var<0)var+=MOD;
			var=var%MOD;
			//cout<<hsh<<" "<<var<<" "<<str[i]<<endl;
			if(var==hsh){pose.pb(i+1);poss.pb(i+2-m);}
		}
		foi(poss.size())
		{
			if(pt[0].substr(pt[0].find("-")+1)==str[poss[i]].substr(str[poss[i]].find("-")+1)&&pt[m-1].substr(pt[m-1].find("-")+1)==str[pose[i]].substr(str[pose[i]].find("-")+1))
			{
				int x=stoi(pt[0].substr(0,pt[0].find("-"))),y=stoi(str[poss[i]].substr(0,str[poss[i]].find("-"))),a=stoi(pt[m-1].substr(0,pt[m-1].find("-"))),b=stoi(str[pose[i]].substr(0,str[pose[i]].find("-")));
				if(y>=x&&b>=a)ans+=(1);

			}
		}
	}

	cout<<ans<<endl;
}