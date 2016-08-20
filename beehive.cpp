#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>


using namespace std;

int main()
{
	unordered_map<int,int> m;
	int var=1,k=6;;
	while(var<1000000000)
	{
		m[var]=1;
		var+=k;
		k+=6;
	}
	cin>>var;
	while(var!=-1)
	{
		if(m.find(var)!=m.end())cout<<"Y"<<endl;
		else cout<<"N"<<endl;
		cin>>var;
	}

}