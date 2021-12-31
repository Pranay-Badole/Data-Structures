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

// max_heap
int kth_small(int arr[],int n,int k){
	priority_queue<int>maxh;
		rep(i,0,n){
			int x=arr[i];
		maxh.push(x);
		if(sz(maxh)>k){
			maxh.pop();
		}
	}
	return maxh.top();
}
 // min_heap
void k_large(int arr[], int n, int k){
	priority_queue<int,vector<int>,greater<int>>minh;
	rep(i,0,n){
			int x=arr[i];
		minh.push(x);
		if(sz(minh)>k){
			minh.pop();
		}
	}
	while(!minh.empty()){
		cout<<minh.top()<<' ';
		minh.pop();
	}
	return;
}
void solve(){	
	int arr[]={2,5,2,6,1,4,8};
	int n=length(arr),k=4;
	cout<<kth_small(arr,n,k)<<endl;
	k_large(arr,n,k);
	
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