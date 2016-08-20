#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		stack<int> s;
		vector<int> v;
		v.resize(n);
		for(int i=0;i<n;i++)cin>>v[i];
			int j=1,k=0;
		bool ans=true;
		while(j!=n&&ans)
		{
			if(k<n){
			if(v[k]==j){j++;k++;}
			else if(v[k]!=j&&!s.empty()&&s.top()==j){s.pop();j++;}
			else if(v[k]!=j){s.push(v[k]);k++;}
		}
		else if(k>=n&&s.top()!=j)ans=false;
		else if(k>=n&&s.top()==j){s.pop();j++;}

		}
		if(ans==false)
		{
			cout<<"no"<<endl;
		}
		else cout<<"yes"<<endl;
		cin>>n;
	}
}