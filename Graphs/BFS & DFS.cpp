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
	#define mkp				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)        for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  for(auto x:v){for(auto y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;

const int M=100000000;


template<typename T>
class Graph{
public:
	map<T,list<pair<T,int>>> adj;

	void add_edge(T u, T v, int dist, bool bidirec){
		adj[u].pb({v,dist});
		if(bidirec){
			adj[v].pb({u,dist});
		}
	}

	void print_adj(){
		for(auto &x: adj){
			cout<<x.fr<<" : ";
			for(auto & y : x.sc){
				cout<<'('<<y.fr<<' '<<y.sc<<')'<<' ';
			}
			cout<<endl;
		}
	}

	void bfs(T root){
		queue<T>q;
		q.push(root);
		map<T,bool>visited;
		
		while(!q.empty()){
			T s = q.front();
			q.pop();
			cout<<s;

			visited[s]=1;
			for(auto x:adj[s]){
			if(!visited[x.fr]){
				visited[x.fr]=1;
				q.push(x.fr);
			}
			
    	 }
	  } 
   }

   void dfs(T root){
   	map < T, int > visited;
   	dfs_helper(root, visited);
   }

   void dfs_helper(T root,map< T,int > &visited){
   	
   	visited[root] = 1;
   	cout << root;
   	for(auto x: adj[root]){
   		if(!visited[x.fr]){
   			visited[x.fr] = 1;
   			dfs_helper(x.fr, visited);
   		}
   	}
   }	


};

void solve(){
	Graph<char> g;
	g.add_edge('0', '1', 4, 0);
	g.add_edge('0', '9', 8, 0);
	g.add_edge('1', '2', 11, 0);
	g.add_edge('2', '0', 8, 0);
	g.add_edge('2', '3', 7, 0);
	g.add_edge('9', '3', 2, 0);
	g.print_adj();
	g.dfs('0');cout<<endl;
  	g.dfs('1');cout<<endl;
  	g.dfs('2');cout<<endl;
  	g.dfs('3');cout<<endl;
  	g.dfs('9');cout<<endl;

}
	signed main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
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
		while(t--) solve(),cout<<endl;
		return 0;
	}