#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define MOD 1000000000000007

bool comp(string p, string q)
{
	if(p.length()<q.length())return true;
	if(p.length()==q.length()&&p<q)return true;
	return false;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<string> vec(n);
	string pass,var;
	foi(n)cin>>vec[i];
	cin>>pass;
	int len=pass.length(),strt=-1,end=-1,pos=-1;
	sort(vec.begin(),vec.end(),comp);
	foi(vec.size()){
		//cout<<vec[i]<<endl;
		if(vec[i]==pass){
			pos=i;
		}
		if(vec[i].length()==pass.length()){
			if(i==0){
				strt=i;
			}
			else if(vec[i-1].length()<pass.length()){
				strt=i;
			}
		}
		if(vec[i].length()>pass.length()){
			if(vec[i-1].length()==pass.length()){
				end=i-1;
			}
		}
	}
	if(end==-1)end=n-1;
	int mnt=0,mxt=0;
	var=vec[strt];
	vec[strt]=pass;
	vec[pos]=var;
	//cout<<strt<<" "<<end<<endl;
	foi(vec.size()){
		mnt++;
		if(i>0&&i%k==0)mnt+=5;
		if(vec[i]==pass)break;
	}
	vec[pos]=pass;
	vec[strt]=var;
	var=vec[end];
	vec[pos]=var;
	vec[end]=pass;
	foi(vec.size()){
		mxt++;
		if(i>0&&i%k==0)mxt+=5;
		if(vec[i]==pass)break;
	}
	cout<<mnt<<" "<<mxt<<endl;

}