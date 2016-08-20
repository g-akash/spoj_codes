#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<stack<int> > s;

void trans(int from,int size,int dest)
{
	int dest1;
	if((dest==2&&from==1)||(dest==1&&from==2))dest1=0;
	else if((dest==0&&from==1)||(dest==1&&from==0))dest1=2;
	else dest1=1;
	if(size==1){int var=s[from].top();s[from].pop();s[dest].push(var);cout<<var<<" "<<from<<" "<<dest<<endl;return;}
	else {trans(from,size-1,dest1);int var=s[from].top();s[from].pop();s[dest].push(var);cout<<var<<" "<<from<<" "<<dest<<endl;trans(dest1,size-1,dest);}
	return;
}

int main()
{
	int n;
	cin>>n;
	s.resize(3);
	for(int i=0;i<n;i++)s[0].push(n-1-i);
	trans(0,n,2);
}
