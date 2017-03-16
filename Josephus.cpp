#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	list<int> participants;
	for(int i=0;i<n;i++)participants.push_back(i);
	list<int> ::iterator it=participants.begin();
	for(int i=0;i<n-1;i++)
	{
		//cout<<*it<<endl;
		for(int j=0;j<k-1;j++)
		{
			it++;
			if(it==participants.end())it=participants.begin();
		}
		it=participants.erase(it);
		if(it==participants.end())it=participants.begin();
		//cout<<*it<<endl;
	}
	cout<<*it<<endl;
}
