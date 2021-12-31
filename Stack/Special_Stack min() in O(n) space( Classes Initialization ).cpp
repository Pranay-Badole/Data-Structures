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

class Special_Stack  // O(n)  Space
{
private:
	stack<int>s;
	stack<int>ss;
public:
	void push(int a){
		s.push(a);
		if(ss.empty()){ss.push(a);}
		else{
			if(ss.top()>=a){     // >= : equal to is necesary otherwise 
				ss.push(a);		 // error for consecutive elements 
			}					 // Check for [18 16 16] without equal sign
		}
		return ; 
	}

	int pop(){
		if(ss.empty()){
			cout << "Already empty :)"<<endl;
			return -1;
		}
		if(s.top()==ss.top()){
			ss.pop();
		}
		int x=s.top();
		s.pop();
		return x;
	}

	int min(){
		if(ss.empty()){
			cout<<"Stack is empty :( "<<endl;
			return -1;
		}
		return ss.top();
	}

	int top(){
		if(ss.empty()){
			cout<<"Stack is empty :( "<<endl;
			return -1;
		}
		return s.top();
	}
};
void solve(){
	Special_Stack s;
	s.top();

    s.push(17);
    s.push(18);
    s.push(16);
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    cout << s.top() << endl;
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