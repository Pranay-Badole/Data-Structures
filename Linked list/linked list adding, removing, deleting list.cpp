	#include "bits/stdc++.h"
	using namespace std;	
	#define int              long long 

	#define pb                push_back
	#define ppb               pop_back
	#define pf                push_front
	#define ppf               pop_front
	#define all(x)            (x).begin(),(x).end()
	#define uniq(v)           (v).erase(unique(all(v)),(v).end())
	#define sz(x)             (int)((x).size())
	#define fr                first
	#define sc                second
	#define pii               pair<int,int>
	#define mkp 				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)       for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 

const int N=300005;
const int M=1e9+7;

class Node{
	public: 
		int data;
		Node* next; 
};
Node *A; 

void print_list(){
	Node* temp=A;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 // "tests_file_suffix": "__tests",
void insert(int x,int n){
	Node * temp=new Node();
	temp->data=x;
	temp->next=NULL;
	if(n==1){
		temp->next= A ;
		A=temp;
	}
	else{
		Node* temp2=A;
		rep(i,0,n-2){
			temp2=temp2->next;
		}
		temp->next=temp2->next;
		temp2->next=temp;
	}
}

void remove(int n){
	if(n==1){
		A=A->next;return;
	}
	Node* temp=A;
	rep(i,0,n-2){
		temp=temp->next;
	}
	temp->next=temp->next->next;
}

void delete_list(){
	Node* temp=A;
	Node* com=NULL;
	while(temp!=NULL){
		com=temp->next;
		delete temp;
		temp=com;
	}
	A=NULL;
}

void solve(){
A=NULL;

insert(1,1);
insert(2,2);
insert(6,1);
insert(5,4);
insert(18,3);
print_list();
cout<<endl;
delete_list();
print_list();

}	
	signed main(){
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);cout.tie(NULL);
		
		#ifdef SIEVE
			sieve();
		#endif
		#ifdef NCR
			init();
		#endif

		int t=1;
		// cin>>t;
		while(t--) solve();
		return 0;
	}