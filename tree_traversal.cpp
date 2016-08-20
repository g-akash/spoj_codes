#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_pre(vector<int> pr, vector<int> in,vector<int> po)
{
	int loc=-1;
	if(pr.size()==0)return true;
	vector<int> left_pr,left_in,right_pr,right_in,left_po,right_po;
	if(pr[0]!=po[po.size()-1])return false;
	for(int i=0;i<in.size();i++)
	{
		if(in[i]==pr[0]){loc=i;break;}
		left_in.push_back(in[i]);
		left_po.push_back(po[i]);
		if(i+1<pr.size())left_pr.push_back(pr[i+1]);
	}
	if(loc==-1)return false;
	for(int i=loc+1;i<in.size();i++)
	{
		right_in.push_back(in[i]);
		right_pr.push_back(pr[i]);
		right_po.push_back(po[i-1]);
	}
	if(check_pre(left_pr,left_in,left_po)&&check_pre(right_pr,right_in,right_po))return true;
	return false;
}

int main()
{
	int n;
	cin>>n;
	vector<int> pr,po,in;
	pr.resize(n);
	po.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>pr[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>po[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	vector<int> t1,t2;
	if(!check_pre(pr,in,po)){cout<<"no"<<endl;return 0;}
	else cout<<"yes"<<endl;
}