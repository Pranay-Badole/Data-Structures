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
	#define auv(v)		      for(auto &x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;

const int M=100000000;

template<typename T>
class graph{
public:
	map< T, list<T> > adj;
	map<T,int>visited;
	map<T,int> low;
	map<T,int> tin;
	int timer = 0;

	set<T>cuts;

	void add_edge(T u, T v, bool bidirec){
		adj[u].pb(v);
		if(bidirec) adj[v].pb(u);
	}

	void adj_print(){
		for(auto x : adj){
			cout << x.fr << " ==> ";
			auv(adj[x.fr]);
		}
	}

	void dfs(T v, T par){
		visited[v] = 1;
		low[v] = tin[v] = timer++;

		int children = 0;
		for(auto to : adj[v]){
			if(to == par){continue;}
			if(visited[to]){
				low[v] = min(low[v], tin[to]);
			}
			else {
				dfs(to, v);
				children++;

				low[v] = min(low[v],low[to]);
				if(tin[v] <= low[to] && par!=-1){
				cuts.insert(v);
				}
			}
		}
		if(par == -1 && children > 1){
			cuts.insert(v);
		} 
	}

	void find_cutpoints(){

		for(auto x : adj){
			if(!visited[x.fr]){
				dfs(x.fr,-1);
			}
		}
		auv(cuts);
	}
};

void solve(){
	
	graph<int>g;

    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(2, 0, 1);
    g.add_edge(0, 3, 1);
    // g.add_edge(4, 3, 1);

    g.adj_print();
	g.find_cutpoints();
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