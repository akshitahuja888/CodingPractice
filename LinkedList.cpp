#include<iostream>
#include<stack>
using namespace std;
class node
{
public:
	int data;
	node* next;

	node(int newdata)
	{
		this->data=newdata;
		this->next=NULL;
	}
};
void display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void insertathead(node* &head,int data)
{
	node* n=new node(data);
	n->next=head;
	head=n;
}
void insertattail(node * &head,int data)
{
	if(head==NULL)
	{
		insertathead(head,data);
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node* n =new node(data);
	temp->next=n;
}
//traverse from last in a linked list...
int kfromlast(node* head,int k)
{
	node* temp=head;
	int i=0;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(i<k-1)
	{
		node* prev=head;
		while(prev->next!=temp)
		{
			prev=prev->next;
		}
		temp=prev;
		i++;
	}
	return temp->data;
}
int main()
{
	int n;
	node* head=NULL;
	while(cin>>n)
	{
		if(n==(-1))
		{
			break;
		}
		insertattail(head,n);
	}
	int k;
	cin>>k;
	cout<<kfromlast(head,k);
	return 0;
}
