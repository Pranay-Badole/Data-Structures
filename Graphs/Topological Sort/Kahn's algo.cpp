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


// Directed Acyclic Graph

// Find the count of incoming edges for each vertex
// Insert all the vertices with 0 incoming edges into the queue.
// Reduce the incoming edges of the neighbours by 1;
// When the in[i] turns 0 for any vertex add it in the queue.

vector<int> topoSort(int N, vector<int> adj[]) 
{
    vector<int> in(N, 0);
    for(int i = 0; i < N; i++) {
        for(auto &to : adj[i]) {
            in[to]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    
    for(int i = 0; i < N; i++) {
        if(in[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        
        for(auto &to : adj[cur]) {
            if(--in[to] == 0) {
                q.push(to);
            }
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    
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