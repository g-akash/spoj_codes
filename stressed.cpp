#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ull unsigned long long int
ull a,b,c,d,k;

ull calc(ull x)
{
	ull ans;
	ans=a;
	ans=ans*x+b;
	ans=ans*x+c;
	ans=ans*x+d;
	//cout<<ans<<endl;
	return ans;
}


int main()
{
	int t;
	//a=2;b=3;c=4;d=5;
	//cout<<calc(8)<<endl;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull x=1,y;
		cin>>a>>b>>c>>d>>k;
		while(calc(x)<=k)x*=2;
		y=x;
		x=0;
		//cout<<x<<" "<<y<<endl;
		while(y-x>1)
		{
			if(calc((x+y)/2)<=k){x=(x+y)/2;}
			else
			{
				y=(x+y)/2;
			}
			//cout<<calc(x)<<" values "<<calc(y)<<endl;
			//cout<<x<<" points "<<y<<endl;
		}
		cout<<x<<endl;
	}
}
	
