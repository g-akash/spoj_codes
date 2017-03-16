#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


int main()
{
	int n,temp;
	cin>>n;
	vi vec(n);
	foi(n){
		cin>>vec[i];
	}
	foi(n-1)
	{
		int mn=1000000005,mnind=0;
		for(int j=i;j<n;j++)
		{
			if(vec[j]<mn)
			{
				mn=vec[j];
				mnind=j;
			}
		}
		while(mnind!=i)
		{
			cout<<mnind<<" "<<mnind+1<<endl;
			temp=vec[mnind];
			vec[mnind]=vec[mnind-1];
			vec[mnind-1]=temp;
			mnind--;
		}
	}
}