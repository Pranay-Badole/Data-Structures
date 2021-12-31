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
	map< T,list<pair<T,int>>> adj;
	map< T, int > visited;
	T cycle_start;
	T cycle_end;
	map<T,T>parent;
	
	void add_edge(T u, T v, int dist, bool bidirec){
		adj[u].pb({v,dist});
		if(bidirec){
			adj[v].pb({u,dist});
		}
	}

	bool dfs(T root){
		visited[root] = 1;

		for(auto j : adj[root]){

			if(visited[j.fr] == 1){
				cycle_end = root;
				cycle_start = j.fr;
				return true;
			}
			else if(visited[j.fr] == 0){
				parent[j.fr] = root;
				if(dfs(j.fr))return true;
			}
		}
		visited[root] = 2;
		return false;
	}

	void find_cycle(){
		cycle_start = -1;
		visited.clear();
		parent.clear();
	
		for (auto x : adj) {
			if(visited[x.fr]==0 && dfs(x.fr)){
				break;
			}		
		}

		if(cycle_start == -1){
			cout<<"Acyclic";
		}
		else{
			cout << "Found Cycle => " << endl;
			vector<T>ans;
			for(auto i = cycle_end; i!=cycle_start; i = parent[i]){
				ans.pb(i);
			}
			reverse(all(ans));
			cout << cycle_start << ' ';
			for(auto x : ans) cout<< x <<' ';
			cout << cycle_start << ' ';
		}
	}
	
};

void solve(){
	Graph<char> g;
	g.add_edge('0', '1', 4, 0);
	// g.add_edge('0', '2', 11, 0);
	g.add_edge('1', '2', 8, 0);
	g.add_edge('1', '3', 8, 0);
	// g.add_edge('2', '3', 8, 0);
	g.add_edge('3', '1', 2, 0);

	 g.find_cycle();

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