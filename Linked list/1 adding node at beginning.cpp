#include<bits/stdc++.h>
using namespace std;
#define llt long long int
#define fin() for(int i=0;i<n;i++)
#define fim() for(int i=0;i<m;i++)
#define fiq() for(int i=0;i<q;i++)

struct node
{
	int data;
	node* link;
};
node* A;
void insert(int x)
{
node* temp= new node();
temp->data=x;
temp->link=A;
A=temp;
}
void print()
{	
	node *temp1=A;
	while(temp1!=NULL)
	{
		cout<<temp1->data<<' ';
		temp1=temp1->link;
	}
	cout<<'\n';
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
A= NULL;
int n,x;
cin>>n;
fin()
{
cout<<"Enter the no. to Enter"<<'\n';
cin>>x;
insert(x);
print();
}
}