#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;


int main()
{
	map<float,int> m;
	set<float> s;
	float x=0.5;
	int i=1;
	while(x<5.3)
	{
		m[x]=i;
		s.insert(x);
		x+=(1.0/(i+2.0));
		i++;
	}
	float var;
	cin>>x;
	while(x!=0.00)
	{
		if(s.find(x)==s.end())
		var=*s.upper_bound(x);
		else var=x;
		cout<<m[var]<<" card(s)"<<endl;
		cin>>x;
	}
}

