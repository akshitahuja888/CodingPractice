#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

class node{

public:
	int data;
	node* right;
	node* left;

	node(int data)
	{
		this->data=data;
		this->right=NULL;
		this->left=NULL;
	}
};

node* buildTree(node* root)
{
	int data;
	cin>>data;

	if(data==-1)
	{
		return NULL;
	}				
	if(root==NULL)
	{
		 root=new node(data);
	}

	root->left=buildTree(root->left);
	root->right=buildTree(root->right);

	return root;
}
void preOrder(node* root)
{
	if(root==NULL)
		return ;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void InOrder(node* root)
{
	if(root==NULL)
		return ;

	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}
void postOrder(node* root)
{
	if(root==NULL)
		return ;
	
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
	
}
int countNodes(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int leftCount=countNodes(root->left);
	int rightCount=countNodes(root->right);

	return leftCount+rightCount+1;
}
int SumOfNodes(node* root)
{
	if(root==NULL)
		return 0;

	int leftSum=SumOfNodes(root->left);
	int rightSum=SumOfNodes(root->right);

	return leftSum+rightSum+root->data;
}
//complexity of height O(n) where n is no. of nodes 
int heightTree(node* root)
{
	if(root==NULL)
	{
		return -1;
	}
	int leftHeight=heightTree(root->left);
	int rightHeight=heightTree(root->right);

	return max(leftHeight,rightHeight)+1;
}
bool Search(node* root,int value)
{
	if(root==NULL)
		return false;

	if(root->data==value)
		return true;

	bool leftSearch=Search(root->left,value);
	bool rightSearch=Search(root->right,value);

	return leftSearch or rightSearch;
}

void levelOrderQueue(node* root)
{
	queue<node*> q;

	q.push(root);

	while(!q.empty())
	{
		node* a=q.front();
		q.pop();

		cout<<a->data<<" ";

		if(a->left)
			q.push(a->left);

		if(a->right)
			q.push(a->right);
	}
	cout<<endl;

}
//one more method for LCA is to ssave all the root to leaf strings of the two nodes 
//and then printing the greatest common value..
//123
//124
//therefore 2 is the lca to 3 and 4


//Level Order Recursive

void PrintKlevel(node* root,int k)
{
	if(root==NULL)
	{
		return;
	}

	if(k==1)
	{
		cout<<root->data<<" ";
	}
	PrintKlevel(root->left,k-1);
	PrintKlevel(root->right,k-1);
}
void LevelOrder(node* root)
{
	int h=heightTree(root);

	for(int i=0;i<=h+1;i++)
	{
		PrintKlevel(root,i);
		cout<<endl;
	}
}
//complexity of diameterTree is O(n^2) as for height it is O(n) and diameter as O(n) in worst cases...
int diameterTree(node* root)
{
	if(root==NULL)
		return 0;

	int leftDia=diameterTree(root->left);
	int rightDia=diameterTree(root->right);

	int leftHeight=heightTree(root->left);
	int rightHeight=heightTree(root->right);

	int meraDia=leftHeight+rightHeight+2;

	return max(meraDia,max(leftDia,rightDia));
}
//Diameter optimized complexity O(n)...
class Dia{

public:
	int diameter;
	int height;
};

Dia DiameterTreeOpt(node* root)
{
	Dia d;

	if(root==NULL)
	{
		d.height=-1;
		d.diameter=0;
		return d;
	}
	Dia leftPair=DiameterTreeOpt(root->left);
	Dia rightPair=DiameterTreeOpt(root->right);

	d.height=max(leftPair.height,rightPair.height)+1;
	d.diameter=max(rightPair.diameter,max(leftPair.diameter,leftPair.height+rightPair.height+2));

	return d;
}
//Lowest Common Ansector.....
node* lca(node* root,int d1,int d2)
{
	if(root==NULL)
		return NULL;

	if(root->data==d1 or root->data==d2)
	{
		return root;
	}

	node* leftLCA=lca(root->left,d1,d2);
	node* rightLCA=lca(root->right,d1,d2);

	if(leftLCA!=NULL and rightLCA!=NULL)
	{
		return root;
	}
	if(leftLCA==NULL and rightLCA==NULL)
	{
		return NULL;
	}

	return rightLCA!=NULL ? rightLCA : leftLCA;

}
int findHeight(node* root,int level,int value)
{
	if(root==NULL)
		return -1;

	if(root->data==value)
		return level;

	int leftMeinHai=findHeight(root->left,level+1,value);

	if(leftMeinHai==-1)
	{
		int rightMeinHaiKya=findHeight(root->right,level+1,value);
		return rightMeinHaiKya;
	}

	return leftMeinHai;
}
int findDist(node* root,int node1,int node2)
{
	node* Common=lca(root,node1,node2);

	int d1=findHeight(Common,0,node1);
	int d2=findHeight(Common,0,node2);

	return d1+d2;
}

//LeetCode 124 MaxSum in a BT...

int MaxSum(node* root,int &result)
{
	if(root==NULL)
		return 0;

	int leftMax=MaxSum(root->left,result);//ho skta h left mein hi ho
	int rightMax=MaxSum(root->right,result);//ho skta h right ka hi ho

	leftMax=max(0,leftMax);//agar negative h to zero bana do
	rightMax=max(0,rightMax);

	result=max(leftMax+rightMax+root->data,result);//agar mujhe include karke zyada aata h to update karo

	return max(leftMax,rightMax)+root->data;//ho sakta h dono mein mein se max ke saath main jau aur koi random pair ban jaye..
} 
int main() {

	node* root=NULL;
	node* tree=buildTree(root);
	// preOrder(tree);
	// cout<<endl;
	// cout<<countNodes(tree)<<endl;
	// cout<<SumOfNodes(tree)<<endl;
	// cout<<heightTree(tree)<<endl;
	// levelOrderQueue(tree);

	// PrintKlevel(tree,2);
	// LevelOrder(tree);

	// cout<<diameterTree(tree)<<endl;
	// Dia ans=DiameterTreeOpt(tree);
	// cout<<ans.diameter<<endl;

	// node* ans=lca(tree,1,3);
	// cout<<ans->data<<endl;
	// cout<<findDist(tree,2,5)<<endl;
	// int answer=INT_MIN;
	// MaxSum(tree,answer);
	// cout<<answer<<endl;
	return 0;
}

//Level Order Input to form a BT....using queue DS
node* buildTree()
{
	int data;
	cin>>data;

	node* root=new node(data);
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node* parent=q.front();
		q.pop();

		int ch1,ch2;
		cin>>ch1>>ch2;

		if(ch1!=-1)
		{
			parent->left=new node(ch1);
			q.push(parent->left);
		}else{
			parent->left=NULL;
		}

		if(ch2!=-1)
		{
			parent->right=new node(ch2);
			q.push(parent->right);
		}else{
			parent->right=NULL;
		}
	}
	return root;
}

//while level order input we can create an int horizontal distance and according print top and bottom view..
