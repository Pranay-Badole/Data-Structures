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
	#define mkp 				  make_pair
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
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;
const int M=100000000;


std::vector<int> next_greater (vector<int> v,int n) {
	stack<int>s;
	std::vector<int> b(n);

	rrep(i,n-1,0){
		// cout<<v[i]<<' ';
		while(!s.empty() && s.top()<=v[i])
			s.pop();

		if(s.empty()){
			b[i]=-1;
		}
		else{b[i]=s.top();}

		s.push(v[i]);

	}

	// rep(i,0,n){cout<<v[i]<<' '<<b[i]<<endl;}	
	return b;
} 

std::vector<int> next_smaller(std::vector<int> v, int n){
	stack<int>s;
	std::vector<int> b(n);
	rrep(i,n-1,0){
		while(!s.empty() && s.top()>=v[i]){
			s.pop();
		}
		if(s.empty()){
			b[i]=-1;
		}
		else{b[i]=s.top();}

		s.push(v[i]);
	}
	// rep(i,0,n){cout<<v[i]<<' '<<b[i]<<endl;}	
	return b;
}
 
void solve(){
		int n; cin >> n;
		std::vector<int> v(n);
		rep(i,0,n)cin>>v[i];
		vector<int>G,Sm; 
		G=next_greater(v,n);
		auv(G);
		cout<<endl;
		Sm=next_smaller(v,n);
		auv(Sm);
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