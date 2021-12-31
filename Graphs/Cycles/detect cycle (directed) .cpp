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


// CP algorithms 

IMP. if the Graph has a back edge then it depicts the presence
of a cycle in the grpah so this what we will do find the back edge

template<typename T>
class Graph{
public:
	map< T,list<pair<T,int>>> adj;
	map< T, int > visited;
	
	void add_edge(T u, T v, int dist, bool bidirec){
		adj[u].pb({v,dist});
		if(bidirec){
			adj[v].pb({u,dist});
		}
	}

	bool find_cycle(){

		for(auto vertex : adj){
			if(!visited[vertex.fr] && dfs_helper(vertex.fr)){
				return true;
			}	
		}
		return false;
	}

	bool dfs_helper(T vertex){
		visited[vertex] = 1;
		
		for(auto j : adj[vertex]){
			if(visited[j.fr] == 1){
				return true;
			}
			else if(visited[j.fr] == 0 && dfs_helper(j.fr)){
				return true;
			}
		}
		visited[vertex] = 2;
		return false;
	}

	
};

void solve(){
	Graph<char> g;
	g.add_edge('0', '1', 4, 0);
	g.add_edge('0', '2', 11, 0);
	g.add_edge('1', '2', 8, 0);
	g.add_edge('2', '0', 8, 0);
	g.add_edge('2', '3', 8, 0);
	g.add_edge('3', '3', 2, 0);

	cout << g.find_cycle();

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