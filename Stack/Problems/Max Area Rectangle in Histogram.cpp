#include "bits/stdc++.h"
	using namespace std;	
	#define int               long long 
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
	
 
const int N=1e9;
const int M=100000000;
 
std::vector<int> prev_smaller(int a[],int n){
	std::vector<int> b(n);
	stack<int>s;
	rep(i,0,n){
		// cout<<sz(s);
		while(!s.empty() && a[s.top()]>= a[i]){
			s.pop();
		}
		if(s.empty()){
			b[i]=-1;
		}
		else{
			b[i]=s.top();
		}
		s.push(i);
	}
		return b;
}

std::vector<int> next_smaller(int a[],int n){
	std::vector<int> b(n);
	stack<int>s;
	rrep(i,n-1,0){
		// cout<<sz(s);
		while(!s.empty() && a[s.top()]>= a[i]){
			s.pop();
		}
		if(s.empty()){
			b[i]=-1;
		}
		else{
			b[i]=s.top();
		}
		s.push(i);
	}
		return b;
}


void solve(){
	int n;cin>>n;
	int a[n];
	rep(i,0,n)cin>>a[i];

	std::vector<int> P, N;
	P=prev_smaller(a,n);
	N=next_smaller(a,n);
	
	// auv(P);cout<<endl;
	// auv(N);cout<<endl;
	
	int ans=-100;
	
	rep(i,0,n){
		int ps=P[i], ns=N[i];
		if(ns==-1){ns=n;}
		ans=max(ans,(ns-ps-1)*a[i]);
	}
	cout<<ans;
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