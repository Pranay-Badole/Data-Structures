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
Node* root = new Node(-1);

void inorder(Node* temp){
	if(temp == NULL) return;

	inorder(temp -> left);
	cout<<temp -> data<<' ';
	inorder(temp -> right);
}

void insert(int x){
	if(root == NULL){
		cout<<"Empty";
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

		if(c -> right!=NULL){
			q.push(c->right);
		}
		else{
			c -> right=new Node(x);
			return ;
		}

	}
}


Node* level_order(char op = 'l'){
	if(root == NULL){
		cout<<"Empty";
		return NULL;
	}
	
	queue< Node* > q;
	Node *prev;

	q.push(root);
	while(!q.empty()){
		bool flag = 1;
		if(op=='l')
		cout << q.front()->data << ' ' ;

		if(q.front() -> left ){
			flag=0;
			q.push(q.front()->left);
		}
		if(q.front() -> right ){
			flag=0;
			q.push(q.front() -> right);
		}
		if(!flag) prev=q.front();
		q.pop();
	}

	return prev;
}
void _delete(int d){
	queue< Node* > q;
	q.push(root);

	Node* prev = level_order('d');
	Node* d_node;
	int flag=0;
	d_node = prev->right;
	if(prev->right == NULL){flag=1;d_node=prev->left;}
	
	while(!q.empty()){
		if(q.front()->data == d){
			q.front()->data = d_node->data;
			delete d_node;
			prev->right=NULL;
			if(flag==1){prev->left = NULL;}
			break;
		}
		else{
			if(q.front()->left!=NULL)
			q.push(q.front()->left);
			if(q.front()->right!=NULL)
			q.push(q.front()->right);
		}
		q.pop();
	}
}

void solve(){
	root= new Node(13);
	root -> left = new Node(12);
	root -> right = new Node(10);
	root -> left -> left= new Node(4);
	root -> left -> right= new Node(19);
	root -> right -> left = new Node(16);
	root -> right -> right = new Node(9);
	// cout << root -> right -> right -> data;

	level_order();
	cout<<endl;	
	_delete(12);
	level_order();
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