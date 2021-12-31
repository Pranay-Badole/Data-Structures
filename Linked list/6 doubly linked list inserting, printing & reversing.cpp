#include<bits/stdc++.h>
using namespace std;
#define llt long long int
#define fin() for(int i=0;i<n-2;i++)
#define fim() for(int i=0;i<m-2;i++)
#define fiq() for(int i=0;i<q;i++)

struct node
{
	int data;
	node* next;
	node* prev;
};
node* head;
void insert(int x,int n)
{	node * temp= new node();
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	if(n==1)
	{
		if(head==NULL)
		{
			head=temp;
			return;
		}
		temp->next=head;
		node* q=head;
		q->prev=temp;
		head=temp;
		return;
	}
	node* temp1=head;
	fin()
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp->prev=temp1;
	node* q= temp1->next;
	if(q!=NULL)
	{
		q->prev=temp;
	}
	temp1->next=temp;
}

void print()
{
	node * temp= head;
	while(temp!=NULL)
	{
		cout<<temp->data<<' ';
		temp=temp->next;	
	}
	cout<<endl;
}

void reverse()
{
	node *p = head;
	if(p==NULL) return;
	while(p->next!=NULL)
	{
		p=p->next;			
	}
while(p!=NULL)
{
	cout<<p->data<<' ';
	p=p->prev;
}

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
	insert(18,2);
	insert(83,1);
	insert(42,4);
	print();
	reverse();
	return 0;
}