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



int main()
{
	vll pos_string(63);
	pos_string[0]=1;
	pos_string[1]=2;
	for(int i=2;i<63;i++)
	{
		pos_string[i]=(ll)2*pos_string[i-1];
	}
	vll tot_string(63);
	tot_string[0]=0;
	tot_string[1]=2;
	for(int i=2;i<63;i++)
	{
		tot_string[i]=tot_string[i-1]+pos_string[i];
	}
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n==1)
		{
			cout<<5<<endl;
			continue;
		}
		int pos;
		for(int i=1;i<63;i++)
		{
			if(tot_string[i]>=n)
			{
				pos=i;
				break;
			}
		}
		vll ans(pos+1);

		//cout<<pos<<" "<<n<<endl;
		if(n>tot_string[pos-1]+pos_string[pos-1])
		{
			ans[pos]=8;
			n-=(tot_string[pos-1]+pos_string[pos-1]);
		}
		else
		{
			ans[pos]=5;
			n-=(tot_string[pos-1]);
		}
		for(int i=pos-1;i>0;i--)
		{
			//cout<<n<<endl;
			if(n>pos_string[i-1])
			{
				ans[i]=8;
				n-=(pos_string[i-1]);
			}
			else
			{
				ans[i]=5;
				if(i!=pos)n-=0;
				else	n-=(tot_string[i-1]);
			}
		}
		for(int i=pos;i>0;i--)cout<<ans[i];cout<<endl;
	}

}