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

void insert(int x){
	if(root == NULL){
		root = new Node(x);
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

void level_order(){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		cout << q.front() -> data << ' ';
		if(q.front()->left){
			q.push(q.front()->left);
		}
		if(q.front()->right){
			q.push(q.front()->right);
		}
		q.pop();
	}
}

bool check(Node* a, Node* b){
	if(a==NULL && b== NULL){
		return true;
	}
	if(a==NULL || b == NULL){
		return false;
	}
	return(a->data==b->data && check(a->left, b->right) && check(a->right, b->left));
}

bool ismirrror(){
	if(root==NULL){
		return true;
	}
	bool flag = check(root->left ,root->right);
	return flag;
}

void solve(){
	insert(1);
	insert(2);
	insert(2);
	insert(3);
	insert(4);
	insert(4);
	insert(3);

	// root -> left -> left  = new Node(9);
	// root -> left -> left  = new Node(9);
	// root -> right -> right = new Node(11);
	// root -> right -> right -> right = new Node(11);
	level_order();
	cout << endl << ismirrror();

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