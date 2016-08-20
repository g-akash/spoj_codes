#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include <iterator>




using namespace std;


int main()
{
	string line;
	int var,ver;
	while(getline(cin,line))
	{
		while(line=="")getline(cin,line);
		istringstream iss(line);
		vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};
		//cout<<tokens.size()<<endl;
		vector<int> nums;
		nums.resize(tokens.size());
		for(int i=0;i<tokens.size();i++)
		{
			nums[i]=stoi(tokens[i]);
		}
		bool ans=true;
		stack<int> nms,szs;
		szs.push(0);
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]<0)
			{
				nms.push(nums[i]);
				szs.push(0);
			}
			else if(nums[i]>0)
			{
				if(szs.empty()){ans=false;break;}
				var=szs.top();
				szs.pop();
				if(nms.empty()){ans=false; break;}
				ver=nms.top();
				nms.pop();
				if(ver!=-1*nums[i]){ans=false;break;}
				//cout<<var<<" "<<nums[i]<<endl;
				if(var>=nums[i]){ans=false; break;}

				ver=szs.top();
				szs.pop();
				ver+=nums[i];
				szs.push(ver);
			}
		}
		if(!szs.empty())
		szs.pop();
		else ans=false;	
		if(!ans||!szs.empty()||!nms.empty()){cout<<":-( Try again."<<endl;}
			else cout<<":-) Matrioshka!"<<endl;
	}

}