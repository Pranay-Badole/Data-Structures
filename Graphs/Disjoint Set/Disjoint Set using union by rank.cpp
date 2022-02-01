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
const ll N = 1e5 + 7;


// here we choose the root_node which has higher rank as adding lower rank node to higher one wont increase
// the rank but doing the opposite would do so, hence increasing complexity.

// when both the roots have same ranks we have no option but choose one of them as root and increase its rank by 1.

class graph{
public:
    vector<int> root;
    vector<int> rank;

    graph(int n):root(n), rank(n) {
        for(int i = 0; i < n; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i) {
        while(root[i] != i){
            i = root[i];
        }
        return i;
    }

    void do_union(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);   

        if(root_a != root_b) {
            if(rank[root_a] > rank[root_b]){
                root[root_b] = root_a;
            }
            else if(rank[root_b] > rank[root_a]){
                root[root_a] = root_b;
            }
            else{
                root[root_b] = root_a;
                rank[root_a]++;
            }
        }
    }

};

void solve(){
    graph g(10);

    int k; cin >> k;
    int a, b;

    g.do_union(1, 2);
    g.do_union(2, 5);
    g.do_union(5, 6);
    g.do_union(6, 7);
    g.do_union(3, 8);
    g.do_union(8, 9);
    g.do_union(9, 4);

    int cnt = 0;

    rep(i, 0, 10){
        if(i == g.root[i]){
            cnt += (i == g.root[i]);
            trace(i);
        }
        cout << g.root[i] << ' ';
    }
    cout << endl << cnt;
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
    cin >> t;

    while(t--) {
        solve();
        cout << endl;
    } 
    return 0;
}   