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
	#define vi 				  vector<int>
	#define vvi 			  vector<vector<int>>



const int N=1e5+5;

const int M=100000000;

void djikstra(int s, vi &d, vi &p, vector<vector<pair<int,int>>> adj){
	
	int n = sz(adj);
	d.assign(n, INT_MAX);
	p.assign(n,-1);
	vi visited(n,0);
	
	d[s] = 0;

	for(int i = 0; i < n; i++){
		int v = -1;
		
		for(int j = 0; j<n; j++){
			if(!visited[j] && (v==-1 || d[j] < d[v])){
				v = j;
			}
		}

		if(d[v] == INT_MAX) break;

		visited[v] = 1;

		for(auto edge : adj[v]){
			int to = edge.fr;
			int len = edge.sc;

			if(d[v] + len < d[to]){
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}

vi restorepath(vi &p, int t, int s){
	vi path;

	for(int v = t; v != s; v = p[v]){
		path.push_back(v);
	}
	
	path.push_back(s);

	reverse(all(path));
	return path;
}

void solve(){
	
	vector<vector<pair<int, int>>> adj;
	vi d;
	vi p;
	int s; // source
	int t; // destination

	djikstra(s, d, p, adj);
	restorepath(p, s, t);

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