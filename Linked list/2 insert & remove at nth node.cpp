#include<bits/stdc++.h>
using namespace std;
#define llt long long int
#define fin() for(int i=0;i<n-2;i++)
#define fim() for(int i=0;i<m-2;i++)
#define fiq() for(int i=0;i<q;i++)

struct node
{
	int data;
	node* link;
};
node* head;

void insert(int x,int n)
{
	node *temp1=new node();
	temp1->data=x;
	temp1->link=NULL;
	if(n==1)
	{
		temp1->link=head;
		head=temp1;
		return;
	}
	node* temp2=head;
	fin()
	{
		temp2=temp2->link;
	}

	temp1->link=temp2->link;
	temp2->link=temp1;
}

void print()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<' ';
		temp=temp->link;
	}
	cout<<'\n';
}
void remove(int m)
{	if(m==1)
	{
		head=head->link;
		return;
	}	
	node* temp1= head;
	fim()
	{
		temp1=temp1->link;
	}
	node* temp2=temp1->link;
	temp1->link=temp2->link;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	head=NULL;
	insert(5,1);
	insert(7,1);
	insert(18,3);
	insert(83,1);
	insert(42,4);
	remove(3);
	print();
	return 0;
}