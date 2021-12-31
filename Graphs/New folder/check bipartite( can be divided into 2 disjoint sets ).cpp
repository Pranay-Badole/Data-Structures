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
	#define aump(mp)	      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
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
	#define vi 				  vector<int>
	#define vvi 			  vector<vector<int>>



const int N=1e5+5;

const int M=100000000;


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj;
        adj.resize(n+1);
        int isbipartite = 1;
        
        for(auto edge : dislikes){
            int l = edge[0];
            int r = edge[1];
            adj[l].push_back(r);
            adj[r].push_back(l);
        }
        vector<int>side(n+1, -1);
        queue<int>pq;
        
        for(int st = 1; st < n+1; st++){
            if(side[st] == -1){ pq.push(st);
            side[st] = 0;
            
            while(!pq.empty()){
                int v = pq.front();
                pq.pop();
                
                for(auto u : adj[v]){
                    if(side[u] == -1){
                        side[u] = !side[v];
                        pq.push(u);
                    }
                    else{
                        if(side[u] == side[v]){
                            isbipartite = 0;
                        }
                    }
                }
            }
        }
    }
        // for(int i = 1; i< n+1 ; i++){
        //     cout<<i << ' ' << side[i] << endl;
        // }
        return isbipartite;
    }

void solve(){

	int n;
	vector<vector<int>>dislikes;

	// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
	// Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]

	possibleBipartition(n, dislikes);	
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