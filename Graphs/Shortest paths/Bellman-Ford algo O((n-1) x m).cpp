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

***IMP***
I think what needs to "click" for you here is that k iterations of BF
only promises to discover the shortest paths to vertices for which the 
shortest path takes k or fewer steps. T's shortest path takes 3 steps, 
so the algorithm doesn't make any promises about T after only 2 iterations
***IMP***

const int N=1e5+5;

const int M=100000000;

class edge{
public:
	int a;
	int b;
	int cost;

	edge(int a, int b, int cost) {
		this->a = a;
		this->b = b;
		this->cost = cost;
	}
};

void bellman_ford(vector<edge> G, int v, int n) 
{
	
	vi d(n,INT_MAX);
	vi p(n,-1);
	d[v] = 0;

	int m = G.size();

	// n-1 iterations
	for(int i = 0; i < n-1; i++)
	{
		int flag = 0;
		
		for(int j = 0; j < m; j++)
		{

			if(d[G[j].a] < INT_MAX)
			{
			
				if(d[G[j].a] + G[j].cost < d[G[j].b]) 
				{
				 	d[G[j].b] = d[G[j].a] + G[j].cost;
					p[G[j].b] = G[j].a;
					flag = 1;
				}
			}
		}
		if(!flag) break;
	}

// *****
// Check Cycle
// after n-1 itrns, one more iteration would 
// tell -ve cycle presence if the distance further decreases

	int x = -1;
	for(int j = 0; j < m; j++)
		{	if(d[G[j].a] < INT_MAX)
			{
				if(d[G[j].a] + G[j].cost < d[G[j].b]) 
				{
				 	x = G[j].b;
				 	p[G[j].b] = G[j].a;
				}
			}
		}

// *****
// Printing Cycle Path

	if (x == -1)
        cout << "No negative cycle from " << v;
    else
    {
    	int y = x;
// to get the vertices that are guaranteed to lie in a negative cycle,
// starting from the vertex x, pass through to the predecessors n times
    	for(int i = 0; i<n; i++) y = p[y];

    	vi path;

    	for(int cur = y; ;cur = p[cur]){
    		path.pb(cur);

    		if(cur == y && path.size()>1){
    			break;
    		}
    	}
    	reverse(all(path));

    	cout << "Negative cycle ==> ";
    	auv(path);
	}



// *******
// Print shortest path from V to T 
	int t;

	if(d[t] == INT_MAX) {
			cout << "NO path from " << v << " to " << t;
	}
	else{
		vi path;

		for(int u = t; u!=-1; u = p[u]){
			path.pb(u);
		}
		reverse(all(path));
		cout << "Path from " << v << " to " << t << " ==> ";
		auv(path);
	}

}

void solve(){
	vector <edge> G;
	int n; // no of vertices
	int v; // source

	bellman_ford(G, v, n);
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