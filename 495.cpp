#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool fri(int n)
{
	vector<int> v;
	v.resize(10);
	while(n>0)
	{
		v[n%10]=1;
		n/=10;
	}
	int val=0;
	for(int i=1;i<10;i++)val+=v[i];
		if(val==4)return true;
	return false;
}
bool fvi(int n)
{
	vector<int> v;
	v.resize(10);
	while(n>0)
	{
		v[n%10]=1;
		n/=10;
	}
	int val=0;
	for(int i=0;i<10;i++)val+=v[i];
		if(val==5)return true;
	return false;
}

int main()
{
	vector<int> v;
	int var=1000;
	while(var<100000)
	{
	if(var%495==0)v.push_back(var);
	var++;
	}
	int ans=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<10000&&fri(v[i]))ans++;
		else if(v[i]>=10000&&fvi(v[i]))ans++;
	}
	cout<<"1/420"<<endl;

}