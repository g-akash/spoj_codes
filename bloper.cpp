#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void poss(int sum, int n)
{
	if(n==1&&sum==1)
	{
		vec[sum][n]=1;
		return;
	}
	else if(n==1)
	{
		sum[sum][n]=0;
		return;
	}
	if(vec[sum][n]>=0)return;
	if()
}

int main()
{
	int n,s;
	cin>>n>>s;
	int sum=(n*(n+1))/2;
	vector<char> vec;
	vec.resize(n+1);
	for(int i=n;i>1;i--)
	{
		if(sum-s>=2*i){sum-=2*i;vec[i]='-';}
		else vec[i]='+';
	}
	if(sum==s)
	{
		for(int i=1;i<n;i++)cout<<i<<vec[i+1];cout<<n<<endl;
	}
	else cout<<"Impossible"<<endl;
}