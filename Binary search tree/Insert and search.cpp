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
		data=a;
		left=NULL;
		right=NULL;
	}
};
Node* root=NULL;

void level_order(){
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		cout<<q.front()->data<<' ';
		if(q.front()->left)q.push(q.front()->left);
		if(q.front()->right)q.push(q.front()->right);
		q.pop();
	}
}

void inorder(Node* temp=root){
	if(temp==NULL)return;
	inorder(temp->left);
	cout<<temp->data<<' ';
	inorder(temp->right);
}

Node* insert(int x, Node* temp ){
	if(temp==NULL){
		return new Node(x);
	}
	if(x > temp->data){
		temp->right=insert(x, temp->right);}
	
	else{ 
		temp->left=insert(x, temp->left);}

	return temp;
}

Node* search(int x, Node* temp=root){
	if(temp==NULL || temp->data == x){
		return temp;
	}
	if(x < temp->data)	return(search(x, temp->left));
	else return (search(x, temp->right));
}

void solve(){
	// root=new Node(2);

	root=insert(8,root);
	insert(3,root);
	insert(10,root);
	insert(1,root);
	insert(6,root);
	insert(4,root);
	insert(7,root);
	insert(14,root);
	insert(13,root);
	
	inorder();

	int t;cin>>t;
	while(t--){
		int f;cin>>f;
		search(f)?cout<<"found":cout<<"not found",cout<<endl;
	}
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