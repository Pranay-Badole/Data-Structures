#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;    
using namespace __gnu_pbds;

    #define ll                            long long
    #define pb                            push_back
    #define ppb                           pop_back
    #define pf                            push_front
    #define ppf                           pop_front
    #define all(x)                        (x).begin(),(x).end()
    #define uniq(v)                       (v).erase(unique(all(v)),(v).end())
    #define sz(x)                         (ll)((x).size())
    #define fr                            first
    #define sc                            second
    #define pii                           pair<ll,ll>
    #define mkp                           make_pair
    #define rep(i,a,b)                    for(ll i=a;i<b;i++)
    #define rrep(i,a,b)                   for(ll i=a;i>=b;i--)
    #define REP(i,a,b)                    for(ll i=a;i<=b;i++)
    #define mem1(a)                       memset(a,-1,sizeof(a))
    #define mem0(a)                       memset(a,0,sizeof(a))
    #define ppc                           __builtin_popcount
    #define ppcll                         __builtin_popcountll
    #define acc                           accumulate
    #define endl                          '\n'
    #define length(a)                     sizeof(a)/sizeof(a[0])
    #define auv(v)                        for(auto &x:v) cout<<x<<' ';cout << endl;
    #define auvv(v)                       for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
    #define aump(mp)                      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl;  
    #define vi                            vector<ll>
    #define vvi                           vector<vector<ll>>
    #define vc                            vector<char>
    #define vvc                           vector<vector<char>>
    #define two(x)                        cout << x.fr << ' ' << x.sc << ' ';
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        std::cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }

    typedef tree<
    ll,
    null_type,
    less<ll>,  // less_equal<ll> for multiset
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
    // find_by_order(k);    returs iterator of Kth element starting from 0;
    // order_of_key(k);     no of elemets strictly less than k;


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


#define EPS 1e-9
const ll M = 1e9 + 7;;
const ll MM = 998244353;
const ll N = 2e5 + 7;

// We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. 
// Following is detailed Kosaraju’s algorithm.

1.
// Create an empty stack ‘S’ and do DFS traversal of a graph. 
// In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. 
// In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.

2.
// Reverse directions of all arcs to obtain the transpose graph. 

3.
// One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
// Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. 


Basically find the topo sort of the graph then in that order and the edges being reversed (rev_adj),
find the total connected components using dfs, that will give us the SCC (Strongly CC)

void dfs(int i, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {

    vis[i] = 1;
    for(auto &to : adj[i]) {
        if(!vis[to]) dfs(to, vis, adj, st);
    }
    cout << i << ' ';
    st.push(i);
}

void dfs_helper(int i, vector<vector<int>> &adj, vector<int> &vis) {
    vis[i] = 1;
    cout << i << ' ';
    for(auto &to : adj[i]) {
        if(!vis[to]) dfs_helper(to, adj, vis);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);

    ll a, b;
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    stack<int> st;
    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vis.assign(n, 0);
    cout << endl;

    int scc = 0;

    while(!st.empty()) {
        if(!vis[st.top()]) {dfs_helper(st.top(), rev_adj, vis); scc++;}
        st.pop();
        
        cout << endl;
    }
    cout << "Strongly Connected Components ==> " << scc;
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
    
    cerr << setprecision(9) << fixed;
    cout << setprecision(9) << fixed;

    ll t = 1;
    // cin >> t;

    while(t--) {
        solve();
        cout << endl;
    } 
    return 0;
}   