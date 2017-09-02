#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> vec;
int n,s;
int sum;

bool inc()
{
	for(int i=2;i<n;i++)
	{
		if(vec[i]=='+'&&vec[i+1]=='-')
		{
			vec[i]='-';
			vec[i+1]='+';
			return true;
		}
	}
	if(vec[2]=='-'&&sum<=s-4)
	{
		vec[2]='+';
		sum+=2;
		return true;
	}
	return false;
}

bool dec()
{
	for(int i=2;i<n;i++)
	{
		if(vec[i]=='-'&&vec[i+1]=='+')
		{
			vec[i]='+';
			vec[i+1]='-';
			return true;
		}
	}
	if(vec[2]=='+'&&sum>=s+4)
	{
		vec[2]='-';
		sum-=2;
		return true;
	}

	return false;
}


int main()
{
	
	cin>>n>>s;
	sum = 0;
	vec.resize(n+1);
	
	if(n%2==0)sum=-(n/2);
	else sum = -(n/2)+n;
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)vec[i]='-';
		else vec[i]='+';
	}
	bool done = true;
	while(sum!=s)
	{
		// cout<<s<<" "<<sum<<endl;
		// cout<<1;
		// for(int i=2;i<=n;i++)cout<<vec[i]<<i;
		// cout<<endl;
		if(sum<=s-2)
		{
			if(!inc())
			{
				cout<<"Impossible"<<endl;
				done = false;
				break;
			}

			sum+=2;
		}
		else if(sum>=s+2)
		{
			if(!dec())
			{
				cout<<"Impossible"<<endl;
				done = false;
				break;
			}
			sum-=2;
		}
		else
		{
			cout<<"Impossible"<<endl;
			done = false;
			break;
		}
	}

	if(done)
	{
		cout<<1;
		for(int i=2;i<=n;i++)cout<<vec[i]<<i;
		cout<<endl;
	}
}