#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ull unsigned long long int

vector<ull> powers_of_22,powers_of_2;

void calc_powers()
{
	ull var=2;
	ull temp=1;
	for(int i=0;i<=30;i++)
	{
		powers_of_22.push_back(var);
		powers_of_2.push_back(temp);
		temp*=2;
		var*=var;
		var%=1000000007;
	}
}

void calc_permutation(int n)
{
	ull ans=1;
	for(int i=30;i>=0;i--)
	{
		if(powers_of_2[i]<=n)
		{
			ans*=powers_of_22[i];
			ans%=1000000007;
			n-=powers_of_2[i];
		}
	}
	cout<<ans<<endl;
}

int main()
{
	calc_powers();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		calc_permutation(n-1);
	}


}