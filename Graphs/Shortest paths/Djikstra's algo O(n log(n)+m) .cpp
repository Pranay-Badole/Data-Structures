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

void djikstra(vector<vector<pair<int, int>>> adj, vi &p, vi &d, int s){
	int n = adj.size();

	p.assign(n,-1);
	d.assign(n,INT_MAX);

	d[s] = 0;

		set<pair<int,int>> q;
		q.insert({0,s});

		while(!q.empty()){
			int v = q.begin() -> sc;
			q.erase(q.begin());
			
			for(auto edge : adj[v]){
				int to = edge.fr;
				int len  = edge.sc;

				if(d[to] > d[v] + len){
					q.erase({d[to],to});
					d[to] = d[v] + len;
					p[to] = v;
					q.insert({d[to],to});
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

	djikstra(adj, p, d, s);
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