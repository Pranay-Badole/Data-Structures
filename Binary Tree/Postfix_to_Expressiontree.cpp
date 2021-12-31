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
	char data;
	Node* left;
	Node* right;

	Node(char a){
		data = a;
		left = NULL;
		right = NULL;
	}
};
Node* root;

void preorder(Node* temp){
	if(temp==NULL) return;
	
	cout << temp->data << ' ' ;
	preorder(temp->left);
	preorder(temp->right);
}

void inorder(Node* temp){
	if(temp == NULL) return;

	inorder(temp -> left);
	cout<<temp -> data << ' ' ; 
	inorder(temp -> right);
}

void postorder(Node * temp){
	if(temp == NULL) return;

	postorder(temp -> left);
	postorder(temp -> right);
	cout<<temp -> data << ' ' ;
}

void insert(char x){
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

Node* Postfix_to_Expressiontree(string s){
	stack<Node*>st;
	Node* t,* t1,*t2;
	rep(i,0,sz(s)){
		if(s[i]>='a' && s[i]<='z'){
			t=new Node(s[i]);
			st.push(t);
		}
		else{
			t=new Node(s[i]);

			t->right=st.top();
			st.pop();
			t->left=st.top();
			st.pop();
			st.push(t);
		}
	}
	t=st.top(); st.pop();
	return t; 
}

void solve(){
	string s="ab+ef*g*-";
	root=Postfix_to_Expressiontree(s);


	// preorder(root);
	// cout<<endl;
	// inorder(root);
	// cout<<endl;
	postorder(root);

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