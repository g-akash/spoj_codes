#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int num_pages;
		cin>>num_pages;
		vector<unsigned long long int> pos,neg;
		int count_zero=0;
		int var;
		for(int j=0;j<num_pages;j++)
		{
			cin>>var;
			if(var>0)pos.push_back(var);
			else if(var==0)count_zero++;
			else neg.push_back(-1*var);
			//cout<<var<<"akash"<<endl;
		}
		sort(pos.begin(),pos.end());
		sort(neg.begin(),neg.end());
		unsigned long long int pos_max=1,neg_max=1;
		for(int j=0;j<pos.size();j++)pos_max*=pos[j];
		for(int j=0;j<neg.size();j++)neg_max*=neg[j];
		if(neg.size()%2==1)neg_max/=neg[0];
		unsigned long long int ans=pos_max*neg_max;
		if(ans>1)cout<<ans;
		else if(ans==1&&(pos.size()>0||neg.size()>1))cout<<ans;
		else if(ans==1&&count_zero>0)cout<<0;
		else cout<<"-"<<neg[0];
		
		cout<<" ";
		pos_max=1;neg_max=1;
		for(int j=0;j<pos.size();j++)pos_max*=pos[j];
		for(int j=0;j<neg.size();j++)neg_max*=neg[j];
		if(neg.size()>0&&neg.size()%2==1){cout<<"-"<<pos_max*neg_max<<endl;}
		else if(neg.size()>0&&neg.size()%2==0){cout<<"-"<<pos_max*(neg_max/neg[0])<<endl;}
		else if(count_zero>0)cout<<0<<endl;
		else cout<<pos[0]<<endl;
	}
}
