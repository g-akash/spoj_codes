#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <set>
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


class course
{
public:
	ll secl,las,studs,courseno,score;

	course()
	{
		secl = 0;
		las = 0;
		score = 0;
		studs = 0;
	}

	bool operator < (const course & c) const
	{
		if(score<c.score)return true;
		if(score==c.score&&courseno<c.courseno)return true;
		return false;
	}

};

int main()
{
	ll c,p,n;
	cin>>c>>p>>n;
	vector<course> vec(c+1);
	course cor;
	foi1(c)
	{
		cor.courseno=(ll)i;
		cor.secl=0;
		cor.las=0;
		cor.studs=0;
		cor.score = (cor.secl+cor.las)*cor.studs;
		vec[i]=cor;
	}
	foi1(n)
	{
		cin>>vec[i].las;
		vec[i].studs = 1;
		vec[i].score = (vec[i].secl+vec[i].las)*vec[i].studs;
	}
	set<course> st;
	foi1(c)
	{
		st.insert(vec[i]);
	}
	set<course>::iterator it;
	vi ans;
	ll var;
	while(cin>>var)
	{
		
		it = st.begin();
		cor = *it;
		st.erase(it);
		ans.pb(cor.courseno);
		cor.secl = cor.las;
		cor.las = var;
		cor.studs+=1;
		cor.score = (cor.secl+cor.las)*cor.studs;
		st.insert(cor);
	}
	foi(ans.size())cout<<ans[i]<<" ";
	cout<<endl;

}