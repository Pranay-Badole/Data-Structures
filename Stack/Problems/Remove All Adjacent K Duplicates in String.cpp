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
	
 
const int N=1e5+5;
const int M=100000000;

// Two pointers Approach
/* string removeDuplicates(string s, int k) {
       int n=sz(s);
       int count[n];
       int i=0;
       for(auto c:s){

       	count[i]= (i>0 && s[i-1]==c) ? count[i-1]+1:1;	
  		s[i]=c;
  		if(count[i]==k){
  			i-=k;
  		}
  		i++;
       }
       cout<<s.substr(0,i);
       return s.substr(0,i);
    }*/

 string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;

        st.push(mkp('#',0));

        rep(i,0,sz(s)){
        	
    	// if(st.empty()){					// This is necessary as st.top()
    	// 	st.push(mkp(s[i],1));		// makes error if st is empty
    	// 	continue;					// so make sure we add an element before top() 
    	// }								//Or use a dummy element ('#', 0) to avoid empty stack.


        	// cout<<st.top().first<<' '<<st.top().second<<endl;
        	if(s[i]==st.top().first){
        		if(st.top().second==k-1){
        			st.pop();
        		}
        		else{
        			st.top().second+=1;
        		}
        	}
        	else{
        		st.push(mkp(s[i],1));
        	}
        }
        string ans="";
        while(!st.empty()){
			int t=st.top().second;
			while(t--){
				ans+=st.top().first;
			}
        	st.pop();
        }
        reverse(all(ans));
        cout<<ans;
        return ans;
    }

void solve(){
	string s="abcd";
	int k=2;
	removeDuplicates(s,k);
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