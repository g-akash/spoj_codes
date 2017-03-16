#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<unsigned long long int> v;



void fac()
{
	v[0]=0;
	v[1]=0;
	for(unsigned long long int i=0;i<10000005;i++)v[i]=0;	
	for(unsigned long long int i=2;i<10000005;i++)
	{
		if(v[i]>0)continue;
		for(unsigned long long int j=i;j<v.size();j+=i){if(v[j]==0)v[j]=i;}
	}
//for(int i=0;i<20;i++)cout<<v[i]<<endl;
for(unsigned long long int i=1;i<10000005;i++)v[i]=v[i-1]+v[i];

}



int main()
{
	v.resize(10000005);
	fac();
	//v[0]=0;v[1]=0;
	unsigned long long int var;
	//for(unsigned long long int i=2;i<10000000;i++)v[i]=v[i-1]+reso(i);
	unsigned long long int t;
	cin>>t;
	for(unsigned long long int i=0;i<t;i++)
	{
		
		cin>>var;
		cout<<v[var]<<endl;
	}


}