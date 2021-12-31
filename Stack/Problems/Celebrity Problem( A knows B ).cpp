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
 
int p,q;

void solve(){
	int n;cin>>n;

	stack<int>s;
	int a[n+1][n+1];
	
	rep(i,1,n+1){
		s.push(i);
	rep(j,1,n+1)
	cin>>a[i][j];}
		
	int A,B;
	while(sz(s)>1){
		A=s.top();
		s.pop();
		B=s.top();
		s.pop();
		if(a[A][B]==1)s.push(B);
		else{s.push(A);}
	}
	int c=s.top();
	rep(k,1,n+1){
		q+=(a[c][k]==1);	
		p+=(a[k][c]==1);
	}
	if(q==0 && p==n-1){
		cout<<"Celebrity ID "<<c-1;
	}
	else{
		cout<<"NO Celebrity";
	}
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