#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
#define ll long long int


vector<ll> books;
ll m,k;


bool possible(ll bsize)
{
	ll var=0,count=0;
	for(int i=books.size()-1;i>=0;i--)
	{
		if(var+books[i]<=bsize&&i+1>=k-count){var+=books[i];}
		else if(var==0||var>bsize)return false;
		else{var=books[i];count++;}

	}
	if(count!=k-1)return false;
	return true;
}

void do_output(ll bsize)
{
	vector<vector<ll> > vec;
	vector<ll> temp;

	ll var=0,count=0;
	for(int i=books.size()-1;i>=0;i--)
	{
		if(var+books[i]<=bsize&&i+1>=k-count){var+=books[i];temp.push_back(books[i]);}
		else{vec.push_back(temp);temp.resize(0);var=books[i];count++;temp.push_back(books[i]);}

	}
	vec.push_back(temp);
	for(int i=vec.size()-1;i>=0;i--)
	{
		for(int j=vec[i].size()-1;j>=0;j--)if(!(i==0&&j==0))cout<<vec[i][j]<<" ";else cout<<vec[i][j];if(i!=0)cout<<"/ ";
	}
cout<<endl;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll sum=0;
		cin>>m>>k;
		books.resize(m);
		for(int i=0;i<m;i++)
		{
			cin>>books[i];
			sum+=books[i];
		}
		//for(int i=0;i<books.size();i++)cout<<books[i]<<" ";cout<<endl;
		sum++;
		ll y=sum,x=0;
		while(y-x>1)
		{
			ll mid = (x+y)/2;
			if(possible(mid)){y=mid;}
			else x=mid;
		}
		//<<y<<endl;
		do_output(y);
	}
}