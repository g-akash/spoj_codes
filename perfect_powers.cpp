#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;



int main()
{
	int t;
	cin>>t;
	vector<int> powers;
	int x=1000005;
	int sqrtx=sqrt(x);
	powers.push_back(1);
	for(int j=2;j<sqrtx;j++)
	{
		int var=j*j;
		while(var<x){powers.push_back(var);var*=j;}
	}
	sort(powers.begin(),powers.end());
	for(int i=0;i<t;i++)
	{
		
		cin>>x;
		int a=0,b=powers.size()-1;
		while(b>a&&powers[a]+powers[b]!=x)
		{
			if(powers[a]+powers[b]<x)a++;
			else if(powers[a]+powers[b]>x)b--;
		}
		if(b==a)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}

		
		
		

