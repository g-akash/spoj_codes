#include<iostream>
#include<unordered_set>
#include<list>
using namespace std;

class node
{
	public:
	int x,y;
	int steps;
	bool operator != (node a)
	{
		if((x==a.x&& y==a.y)||(x==a.y && y==a.x))return false;
		else  return true;
	}
};

struct hashing
{
    size_t operator()(const node n) const
    {
		int a= n.x+n.y;
		if(n.x<n.y)
    	return ((a)*((a+1)/2)+n.x-1);
    	else
    	return ((a)*((a+1)/2)+n.y-1);
    }
};


struct iequal_to
    : std::binary_function<node, node, bool>
{
    bool operator()(node const& a,
        node const& b) const
    {
        if((b.x==a.x && b.y==a.y)||(b.x==a.y && b.y==a.x))return true;
		else  return false;
    }
};

bool equ(node current_node, node target)
{
	if(current_node.x==target.x&&current_node.y==target.y)return true;
	if(current_node.x==target.y&&current_node.y==target.x)return true;
	return false;
}

int main()
{
	//unordered_set<node> u;
	unordered_set<node,hashing,iequal_to> first;
	node target;
	cin>>target.x>>target.y;
	node start;
	start.x=0;start.y=1;
	start.steps=0;
	node var;
	list<node> comp_states;
	list<node>::iterator it;
	comp_states.push_back(start);
	it=comp_states.begin();
	while(comp_states.empty()==false&&*it!=target)
	{
		//cout<<it->steps<<endl;
		start=*it;
		it++;
		first.insert(start);
		//comp_states.pop();
		var.steps=start.steps+1;
		var.x=2*start.x;var.y=start.y;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(var);
		var.x=start.x-start.y;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.x=start.x+start.y;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.x=2*start.y;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.x=start.y-start.x;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.x=0;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.y=2*start.y;var.x=start.x;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.y=start.x-start.y;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.y=start.x+start.y;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.y=2*start.y;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.y=start.y-start.x;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		var.y=0;if(first.find(var)==first.end())comp_states.push_back(var);first.insert(start);
		
		}
		cout<<it->steps<<endl;
	
	
	
}
