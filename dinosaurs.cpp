#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;



int main()
{
	int n,k,l,q;
	cin>>n>>k>>l>>q;
	map<unsigned long long int,string> m;
	unsigned long long int fin,var;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		fin=0;
		for(int j=0;j<k;j++){cin>>var;fin=fin*100+var;}
			//cout<<fin<<endl;
			m[fin]=s;
	}
	for(int i=0;i<q;i++)
	{
		fin=0;
		for(int j=0;j<k;j++){cin>>var;fin=fin*100+var;}
			if(m.find(fin)==m.end())cout<<"You cant fool me :P"<<endl;
			
		 else cout<<m[fin]<<endl;

	}
}