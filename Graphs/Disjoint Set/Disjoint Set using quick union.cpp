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


int find_parent(int a, vector<int> &parent) 
    {
        
        while(parent[a]!=a){
            a = parent[a];
        }
        return a;
    }
    
int union_find(int n, vector<vector<int>>& connections) 
    {
        
        vector<int>parent(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        
        for(auto edge : connections){
            int a = edge[0];
            int b = edge[1];
            
            int x = find_parent(a,parent);
            int y = find_parent(b,parent);
            
            if(x!=y){
                parent[y] = x;
            }
        }
        
        int dis_tot = 0;

        for(int i = 0; i<n; i++){
           if(parent[i] == i) dis_tot++;
        }

 		// dis_tot - total no of connected components
        return dis_tot; 
    }	

void solve(){

	// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]


	vector<vector<int>> connections; 
	int n;

	union_find(n, connections);

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