#include <iostream>
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

int main()
{
	int s;
	string tim,ans="";
	cin>>s>>tim;
	if(s==12)
	{
		int hour,min;
		hour = stoi(tim.substr(0,2));
		min = stoi(tim.substr(3,2));
		
		if(hour==00)ans="10:";
		else if(hour>12&&hour%10!=0)ans="0"+tim.substr(1,1)+":";
		else if(hour>12&&hour%10==0)ans="10:";
		else ans=tim.substr(0,3);
		if(min>=60)ans=ans+"0"+tim.substr(4,1);
		else ans=ans+tim.substr(3,2);

	}
	else if(s==24)
	{
		int hour,min;
		hour = stoi(tim.substr(0,2));
		min = stoi(tim.substr(3,2));
		
		if(hour>=24)ans="0"+tim.substr(1,1)+":";
		else ans=tim.substr(0,2)+":";
		if(min>=60)ans=ans+"0"+tim.substr(4,1);
		else ans=ans+tim.substr(3,2);
	}
	cout<<ans<<endl;

}