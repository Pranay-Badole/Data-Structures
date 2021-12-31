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
 

	typedef pair<int,pair<int,int>> ppi;
	
const int N=200005;
const int M=998244353;

class mycomp{
public: 
constexpr bool operator() (pii a, pii b){
	return a.second < b.second;
}
};

// minimum 2 values to be chosen

int fun(vector<int> v, int k1, int k2){
	if(k1<k2){swap(k1,k2);}
	priority_queue<int>maxh;
	int ans=0;
	for(auto x:v){
		maxh.push(x);
		if(sz(maxh)>k1){
			maxh.pop();
		}
	}
	
	maxh.pop();
	while(sz(maxh)>k2){
		ans+=maxh.top();
		maxh.pop();
	}	
	return ans;
}

void solve(){	
	std::vector<int> v = {1,3,12,5,15,11};
	int k1,k2;
	k1 = 2;
	k2 = 6; 
	int ans;
	ans = fun(v, k1, k2);
	cout << ans;
}
	signed main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			// freopen("output.txt","w",stdout);
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