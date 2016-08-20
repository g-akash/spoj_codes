#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> numbers;
	numbers.resize(n);
	for(int i=0;i<n;i++)cin>>numbers[i];
	sort(numbers.begin(),numbers.end());
	for(int i=0;i<n;i++)if(numbers[n-1]<=2*numbers[i]){cout<<i<<endl;break;}
	//cout<<i<<endl;
}
