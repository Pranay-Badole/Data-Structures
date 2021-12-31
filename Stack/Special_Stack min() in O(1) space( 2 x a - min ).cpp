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

class Special_Stack  // O(1)  Space
{
private:
	stack<int>s;
	stack<int>ss;
public:
	int min=-1;

	void push(int a){
		if(s.empty()){s.push(a);min=a;}
		else{
			if(min>a){
				s.push(2*a-min);
				min=a;
			}
			else{
				s.push(a);
			}
		}
	}

	int pop(){
		if(s.empty()){
			cout << "Already empty :)"<<endl;
			return -1;
		}
		else{
			int a=s.top();
			s.pop();
			if(a<min){min=2*min-a;}

			return a;
		}
	}

	int minm(){
		if(s.empty()){cout << "Stack is Empty :(" << endl;return -1;}
		 
		return min;
	}

	int top(){
		if(s.empty()){cout << "Stack is Empty :(" << endl;return -1;}
		else{
			if(s.top()<min){return min;}
			
			return s.top();
		}
	}
};
void solve(){
	Special_Stack s;

    s.push(3);
    s.push(2);
    s.push(1);
    cout << s.top() << endl;
    s.pop();
    cout << s.top();
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