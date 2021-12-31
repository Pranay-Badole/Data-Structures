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

class MyHashSet{
private:
	int prime;
	vector<vector<int>>v = vector<vector<int>>(N);  

// 	The parameter for constructors of data members should be written in the initializer list of your class' constructor. That is, instead of
// 
// class Foo {
//     vector<double> dQdt(3);
// };
// You should write

// class Foo {
// private:
//     vector<double> dQdt;
// public:
//     Foo() : dQdt(3) {}
// };
	
public:
	MyHashSet() : prime(N){}

	int hash(int key){
		return(key%prime);
	}

	void add(int key){
		int h = hash(key);
		int flag=1;

		for(auto x: v[h]){			 
			if(x==key){
				flag=0;
			}
		}
		if(flag){v[h].pb(key);}

	} 

	void remove(int key){
		int h=hash(key);
		for(auto it=v[h].begin();it!=v[h].end();it++){
			if(*it==key){
				v[h].erase(it);
				break;
			}
		}
	}

	bool contains(int key){
		int h=hash(key);
		for(auto it=v[h].begin();it!=v[h].end();it++){
			if(*it==key){
				return true;
				break;
			}
		}
		return false;
	}
	// void data(int h){
	// 	auv(v[h]);		
	// }
};


void solve(){
	MyHashSet* obj = new MyHashSet();
	obj->add(2);
	cout<<obj->contains(2);
	cout<<obj->contains(2);
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