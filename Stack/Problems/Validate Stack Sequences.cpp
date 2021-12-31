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


 bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
 	int n=sz(popped);
 	stack<int>s;
 	int l,r; l=r=0;
 	bool flag=1;
 	while(1){
 		if(r==n && l==n){
 			break;
 		}
 		if(s.empty()){ s.push(pushed[l]); l++; }
 		while(s.top()!=popped[r] && l<n){
 			s.push(pushed[l]);
 			l++;
 		}
 		if(s.top()!=popped[r]){
 			flag=0;break;
 		}
 		else{
 			s.pop();
 			r++;
 		}
 	}
 	cout<<flag;
 	return flag;
 }

void solve(){
	vector<int>pushed={1,2,3,4,5};
	vector<int>popped={1,5,4,2,3};

	validateStackSequences(pushed,popped);
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