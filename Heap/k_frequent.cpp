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

// class mycomp{
// public: 
// constexpr bool operator() (pii a, pii b){
// 	return a.second < b.second;
// }
// };

vector<int> k_frequent(std::vector<int> v, int n, int k){
	priority_queue<pii,vector<pii> ,greater<pii>> minh;
	unordered_map<int, int> mp;
	rep(i,0,n){
		mp[v[i]]++;
	}
		int i=0;
		for(auto x:mp){minh.push({x.sc,x.fr});
		if(sz(minh)>k)	{minh.pop();}
		}
		// cout<<minh.top().fr<<' '<<minh.top().sc;
	
	std::vector<int> ans;
	while(sz(minh)){
		ans.pb(minh.top().sc);
		minh.pop();
	}
	return ans;
}

void solve(){	
	std::vector<int> v = {5,2,3,4,1,4};
	int k=3;
	int n=sz(v);
	std::vector<int> ans;
	ans = k_frequent(v,n,k);
	reverse(all(ans));
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