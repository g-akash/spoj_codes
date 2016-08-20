#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main()
{
	int t;
	cin>>t;
	float hh,mm;
	for(int i=0;i<t;i++)
	{
		float ma,ha;
		cin>>hh>>mm;
		if(hh>=12.0)hh-=12.0;
		ma=(mm*6.0);
		ha=hh*30.0;
		ha=-1.0*ha;
		ha+=(mm*5.5);
		if(ha<0.0)ha*=-1;
		if(ha>180.0)ha=360.0-ha;
		cout<<ha<<endl;

	}
}