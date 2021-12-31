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

void inorder(Node* temp){
	if(temp == NULL) return;

	inorder(temp -> left);
	cout<<temp -> data<<' ';
	inorder(temp -> right);
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

void solve(){
	insert(10);
	root -> left = new Node(11);
	root -> right = new Node(9);
	root -> left -> left= new Node(7);
	root -> left -> right= new Node(12);
	// root -> right -> left = new Node(15);
	root -> right -> right = new Node(8);
	// cout << root -> right -> right -> data;
	inorder(root);
	insert(1);
	cout<<endl;
	inorder(root);
	cout<<endl;
	inorder_iter();

}

	signed main(){
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);cout.tie(NULL);
		
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			// freopen("output.txt","w",stdout);
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