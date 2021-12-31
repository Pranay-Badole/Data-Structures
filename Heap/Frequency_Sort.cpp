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
	#define mem1(a)   
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
 
const int N=200005;
const int M=998244353;

class mycomp{
public: 
constexpr bool operator() (pii a, pii b){
	return a.second < b.second;
}
};

vector<int> frequency_sort(std::vector<int> v, int n, int k){
	priority_queue<pii> maxh;
	unordered_map<int, int> mp;
	rep(i,0,n){
		mp[v[i]]++;
	}
		int i=0;
		for(auto x:mp){maxh.push({x.sc,x.fr});}

		// cout<<maxh.top().fr<<' '<<maxh.top().sc;
	
	vector<int> ans;
	while(sz(maxh)){
		int freq=maxh.top().fr;
		while(freq--){ans.pb(maxh.top().sc);}
		maxh.pop();
	}
	return ans;
}

void solve(){	
	std::vector<int> v = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
	int k=3;
	int n=sz(v);
	vector<int> ans;
	ans = frequency_sort(v,n,k);
	auv(ans);
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
		while(t--) solve();
		return 0;
	}