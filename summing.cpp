#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
	int n,m,sum1=0,sum2=0;
	vector<int> s,q;
	cin>>n;
	s.resize(n);
	for(int i=0;i<n;i++){cin>>s[i];sum1+=s[i];}
	cin>>m;
	q.resize(m);
	for(int i=0;i<m;i++){cin>>q[i];sum2+=q[i];}
	int j=0,k=0;
	if(sum2/m<sum1/n){
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<" ";
	}
	}
	else 
	for(int i=0;i<m;i++)cout<<q[i]<<" ";
	cout<<endl;
}
