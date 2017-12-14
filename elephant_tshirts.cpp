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
#include <sstream>

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
vector<umm(string,ll) > vec;
vvll allowed;
string all = "",don="";

ll get_res(int pos,string lef)
{
	//cout<<pos<<endl;
	//cout<<pos<<" "<<lef<<endl;
	if(pos>=100)
	{
		if(lef!=don)return 0;
		else return 1;
	}
	if(lef==don)
	{
		return 1;
	}
	if(vec[pos].find(lef)!=vec[pos].end())
	{
		return vec[pos][lef];
	}
	ll curr_ans = 0;
	curr_ans+=get_res(pos+1,lef);
	string nstr;
	if(lef[0]=='0'&&allowed[pos][0]==1)
	{
		nstr="1"+lef.substr(1);
		curr_ans+=get_res(pos+1,nstr);
	}
	foi1(lef.length()-1)
	{
		if(lef[i]=='0'&&allowed[pos][i]==1)
		{
			nstr = lef.substr(0,i)+"1"+lef.substr(i+1);
			curr_ans+=get_res(pos+1,nstr);
		}
	}
	curr_ans%=1000000007;
	vec[pos][lef]=curr_ans;
	return curr_ans;


}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		char ch;
		cin.get(ch);
		vec.resize(0);
		vec.resize(100);
		foi(100)
		{
			vec[i].clear();
		}
		allowed.resize(0);
		allowed.resize(100);
		foi(100)allowed[i].resize(n);
		string s,c;
		all = "";
		don = "";
		foi(n)
		{
			all+="0";
			don+="1";
			getline(cin,s);
			//cout<<s<<endl;
			istringstream iss(s);
			while(iss>>c)
			{
				allowed[stoi(c)-1][i]=1;
				//cout<<stoi(c)<<endl;
			}
		}
		ll ans = get_res(0,all);
		cout<<ans<<endl;
		




	}
}