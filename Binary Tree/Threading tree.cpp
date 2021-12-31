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
	Node* left;
	Node* right;

	Node(int a){
		data = a;
		left = NULL;
		right = NULL;
	}
};
Node* root;

void inorder(Node* temp=root){
	if(temp == NULL) return;

	inorder(temp -> left);
	cout<<temp -> data<<' ';
	inorder(temp -> right);
}

void insert(int x){

	if(root == NULL){
		root=new Node(x);
		return;
	}

	queue< Node* > q;
	q.push(root);
	while(!q.empty()){
		Node* c = q.front();
		q.pop();
		if(c -> left!=NULL){
			q.push(c->left);
		}
		else{
			c->left=new Node(x);
			return ;
		}

		if(c -> right){
			q.push(c->right);
		}
		else{
			c -> right=new Node(x);
			return ;
		}

	}
}

void inorder_iter(){
	if(root==NULL){cout<<"Empty Tree";return ;}
	
	stack<Node*>st;
	Node* current = root;
	
	while(1){

		if(current == NULL && st.empty()){break;}
		
		while(current!=NULL){
			st.push(current);
			current=current->left;
		}

		cout<<st.top()->data<<' ';
		current=st.top()->right;
		
		st.pop();
	}
}


void threading_tree(){

	Node * temp = root;
	while(temp!=NULL){

		if(temp->left==NULL){
			cout<<temp->data<<' ';
			temp=temp->right;
		}

		else{
			Node *q=temp->left;
			while(q->right!=NULL && q->right!=temp){q=q->right;} // I forgot this statement
			if(q->right==temp){									 // " && q->right!=temp " it goes and goes in the loop;				
				q->right=NULL;
				cout<<temp->data<<' ';
				temp=temp->right;
			}
			else{
				q->right=temp;
				temp=temp->left;
			}
		}
	
	}
}


void solve(){

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);

	inorder();
	cout<<endl;
	inorder_iter();
	cout<<endl;

	threading_tree();
}

	signed main(){
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);cout.tie(NULL);
		
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif

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