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

node* insert(node* P,int x,int n)
{
	node *temp1=new node();
	temp1->data=x;
	temp1->link=NULL;
	if(n==1)
	{
		temp1->link=P;
		P=temp1;
		return P;
	}
	node* temp2=P;
	fin()
	{
		temp2=temp2->link;
	}

	temp1->link=temp2->link;
	temp2->link=temp1;
	return P;
}

void FRprint(node *p)
{	if(p==NULL)
	return;
	cout<<p->data<<' ';
	FRprint(p->link);
}

void RRprint(node *p)
{	if(p==NULL)
	return;
	RRprint(p->link);
	cout<<p->data<<' ';
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	head=NULL;
	head=insert(head,5,1);
	head=insert(head,7,1);
	head=insert(head,18,3);
	head=insert(head,83,1);
	head=insert(head,42,4);
	node* p=head;
	FRprint(p);
	cout<<'\n';
	RRprint(p);
	return 0;
}