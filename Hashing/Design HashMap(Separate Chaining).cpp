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
	#define pii              pair<int,int>
	#define mkp 				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)       for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
 

	typedef pair<int,pair<int,int>> ppi;
	
const int N=1007;
const int M=998244353;

class MyHashMap {
private:
    vector<vector<pii>>v;
    int prime;
public:
    /** Initialize your data structure here. */
    MyHashMap() : prime(N), v(N,vector<pii> {}){}
    
    int hash (int key){
        return(key%prime);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int flag=1;
        int h = hash(key);
        for(auto it=v[h].begin();it!=v[h].end();it++){
            if(it->fr==key){
                flag=0;
                it->second=value;
            }
        }
        if(flag)v[h].pb({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        int ans = -1;
        for(auto it=v[h].begin();it!=v[h].end();it++){
            if(it->fr==key){
                ans=it->sc;                
                break;
            }
        }
        return ans;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        for(auto it=v[h].begin();it!=v[h].end();it++){
            if(it->fr==key){
                v[h].erase(it);
                break;
            }
        }
    }
};


void solve(){
	MyHashMap* obj = new MyHashMap();
	obj->put(1,2);
	cout<<obj->get(1);
	obj->remove(1);x
	cout<<obj->get(1);
}
	signed main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif
		// #ifdef SIEVE
		// 	sieve();
		// #endif
		// #ifdef NCR
		// 	init();
		// #endif

		int t=1;
		// cin>>t;
		while(t--) solve();
		return 0;
	}