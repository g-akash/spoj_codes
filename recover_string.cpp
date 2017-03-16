#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define vi vector<ll>


int main()
{
	ll a00,a01,a10,a11;
	cin>>a00>>a01>>a10>>a11;
	ll x,y;
	vector<char> vec;
	x=sqrt(double(1+8*a00));
	y=sqrt(double(1+8*a11));
	if(!(x*x==(ll)1+(ll)(8)*a00&&y*y==(ll)1+(ll)8*a11))
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		x=(1+x)/2;
		y=(1+y)/2;
		if(a00==0&&a10==0&&a01==0)x=0;
		if(a11==0&&a10==0&&a01==0)y=0;
		if(x+y==0)
		{
			cout<<"1"<<endl;
		}
		else if(x*y!=a01+a10)
		{
			cout<<"Impossible"<<endl;
		}
		
		else
		{
			//string ans="";
			while(a01>0||x>0||y>0)
			{
				//cout<<a01<<" "<<x<<" "<<y<<" "<<ans<<endl;
				if(a01>=y&&x>0)
				{
					//ans+="0";
					vec.pb('0');
					a01-=y;
					x--;
				}
				else
				{
					//ans+="1";
					vec.pb('1');
					y--;
				}

			}
			//cout<<ans<<endl;
			if(vec.size()<=1000000)
			{	
				foi(vec.size())
				{
					cout<<vec[i];
				}
				cout<<endl;
			}
			else
			{
				cout<<"Impossible"<<endl;
			}
		}

		
	}
}