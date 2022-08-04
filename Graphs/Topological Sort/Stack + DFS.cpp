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


// Suppose these are the given paths
// 5 -> 2 -> 3
// 4 -> 1
// 4 -> 5

// So in topo sort, the dependent should come after the determinant
// i.e A -> B === B depends on A so in topo sort B should come after A

// Soln
// Carry on the usual dfs as we do but don't print the element in dfs order.
// instead store it in the stack on the way back.
// i.e the stack will store the topo sort such that the determinant will always be on top of the dependant.

// 5 -> 2 -> 3

// we traverse 5 to 2 to 3. on way back we store it in stack.

                | 5 |
                | 2 |
                |_3_|

// 4 -> 1

                | 4 |
                | 1 |    
                | 5 |
                | 2 |
                |_3_|

// 4 -> 5
// 4 is already visited and 5 is also visited

// thus we get our topo sort
// ==> "4 1 5 2 3"

void dfs(int v, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    
    vis[v] = 1;
    for(auto &to : adj[v]) {
        if(!vis[to]) {
            dfs(to, adj, vis, st);
        }
    }
    st.push(v);
}

vector<int> topoSort(int n, vector<int> adj[]) 
{   
    stack<int> st;
    vector<int> vis(n, 0);
    
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    
    vector<int> ans;
    while(st.size()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void solve() {
    int N; cin >> N;
    vector<int> adj[N];

    // Input adjacency list

    topoSort(N, adj);
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