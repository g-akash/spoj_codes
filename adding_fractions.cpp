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


class frac{
public:
	ll num,den,nex;

	frac()
	{
		num=0;
		den=1;
		nex = 0;
	}
	frac(ll a, ll b, ll c)
	{
		num=a;
		den=b;
		nex = c;
	}
};

bool greaterr(frac p, frac q)
{

	if((p.num*q.den)<=(p.den*q.num))
	{
		//cout<<p.num*q.den<<" greaterr "<<p.den*q.num<<endl;
		return true;
	}
	return false;
}

ll gcd(ll a, ll b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}


int main()
{
	int t;
	cin>>t;
	vector<frac> vec;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		vec.resize(n);
		foi(n)
		{
			cin>>s;
			//cout<<stoi(s1)<<" "<<stoi(s2)<<endl;
			frac f(stol(s.substr(0,s.find("/"))),stol(s.substr(s.find("/")+1)),i+1);
			vec[i]=f;
		}
		frac f ((ll)-1,(ll)1,(ll)0);
		vec.pb(f);
		for(int i=n-2;i>=0;i--)
		{
			//cout<<i<<endl;
			int nex = vec[i].nex;
			while(greaterr(vec[i],vec[nex])==true)
			{
				//cout<<vec[i].num<<" "<<vec[i].den<<" "<<nex<<endl;
				vec[i].num+=vec[nex].num;
				vec[i].den+=vec[nex].den;
				vec[i].nex=vec[nex].nex;
				nex = vec[i].nex;
			}
		}
		foi(n)
		{
			ll gd = gcd(vec[i].num,vec[i].den);
			printf("%lld/%lld\n",vec[i].num/gd,vec[i].den/gd);
		}
		printf("\n");

	}
}