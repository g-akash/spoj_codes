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
#define DIV % 1000000007


/*
0, 1,1,2,3,5,8,13,21,34,55...
0,2,13,

f(4n-2)+f(4n-3)
*/




class matrix
{
public:
	ll a,b,c,d;

	matrix()
	{
		a=0;
		b=0;
		c=0;
		d=0;
	}

	matrix(ll a11, ll a12, ll a21, ll a22)
	{
		a=a11;
		b=a12;
		c=a21;
		d=a22;
	}

	matrix operator*(matrix m)
	{
		matrix ans;
		ans.a = ((a*m.a) DIV + (b*m.c) DIV ) DIV; 
		ans.b = ((a*m.b) DIV + (b*m.d) DIV ) DIV;
		ans.c = ((c*m.a) DIV + (d*m.c) DIV ) DIV;
		ans.d = ((c*m.b) DIV + (d*m.d) DIV ) DIV;
		return ans;
	}

	matrix inverse()
	{
		matrix ans;
		ans.a = d;
		ans.b = -c;
		ans.c = -b;
		ans.d = a;
		return ans;
	}

	ll det()
	{
		return a*d-b*c;
	}
};



matrix power(matrix m, ll x)
{
	matrix ans(1,0,0,1);
	matrix var = m;
	while(x!=0)
	{
		if(x%2==1)
		{
			ans = ans*var;
		}
		else
		{

		}
		var = var*var;
		x/=2;
	}
	return ans;
}

ll intpower(ll a, ll b)
{
	ll ans = 1;
	ll var = a;
	while(b!=0)
	{
		if(b%2==1)
		{
			ans*=var;
			ans = ans DIV;
		}
		b/=2;
		var = var*var;
		var = var DIV;
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n==0)
		{
			cout<<0<<endl;
		}
		else if(n==1)
		{
			cout<<2<<endl;
		}
		else
		{
			matrix init(1,1,1,0);
			init = init*init*init*init;
			//cout<<init.a<<" "<<init.b<<" "<<init.c<<" "<<init.d<<endl;
			//cout<<n<<endl;
			matrix ans = power(init,n);
			//cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<endl;
			ans.a-=1;
			ans.d-=1;
			
			init.a-=1;
			init.d-=1;
			ll deter = init.det();
			//cout<<deter<<endl;
			init = init.inverse();

			ans = init*ans;
			//cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<endl;
			ll fin_ans = (ans.a*2+ans.b*1);
			//cout<<fin_ans<<" "<<deter<<endl;
			//while(fin_ans<0) fin_ans+=1000000007;
			ll tmp = intpower(deter,1000000005);
			ll finans = (fin_ans*tmp);
			finans%=1000000007;
			while(finans<0)finans+=1000000007;
			cout<<finans<<endl;
		}
	}
}