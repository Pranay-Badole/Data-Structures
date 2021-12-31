#include "bits/stdc++.h"
    using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int>s;
        s.push(0);
        for(auto x:S){
            if(x=='('){s.push(0);}
        else{
            int add;
            int t=s.top();
            s.pop();
            if(t>0){
                add=2*t;
            }
            else{
                add=1;
            }
            s.top()+=add;
        }
        }
        return s.top();
    }
};
