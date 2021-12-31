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

void k_closest(std::vector<int> v,int k, int x){       //sorting heap by first element of pair
	priority_queue<pii>maxh;

	for(auto a:v){
		maxh.push({abs(a-x),a});
		if(sz(maxh)>k)maxh.pop();		
	}

	while(sz(maxh)){
		cout<<maxh.top().second<<' ';
		maxh.pop();
	}
}

void K_CLOSEST(std::vector<int> v,int k, int x){     // sorting heap by second element of pair
	priority_queue<pii,vector<pii>,mycomp>maxh;

	for(auto a:v){
		maxh.push({a,abs(a-x)});
		if(sz(maxh)>k)maxh.pop();		
	}

	while(!maxh.empty()){
		cout<<maxh.top().fr<<' ';
		maxh.pop();
	}
}

void solve(){	
	std::vector<int> v = {5,6,7,8,9};
	int k=3,x=6;
	K_CLOSEST(v,k,x);
	cout<<endl;
	k_closest(v,k,x);

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