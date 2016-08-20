#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int a,d;
	cin>>a>>d;
	while(a!=0||d!=0)
	{
		
		
		vector<int> va,vd;
		va.resize(a);
		vd.resize(d);
		for(int j=0;j<a;j++)cin>>va[j];
		for(int j=0;j<d;j++)cin>>vd[j];
			sort(va.begin(),va.end());
		sort(vd.begin(),vd.end());
		if(va[0]<vd[1])cout<<"Y"<<endl;
		else cout<<"N"<<endl;
		cin>>a>>d;
	}
}