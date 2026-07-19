#include<bits/stdc++.h>
using namespace std;
class MinStack {
    public:
        // tc: O(1), sc: O(n)
        stack<pair<int,int>> st; // top,min
        MinStack() {
            
        }
        
        void push(int value) {
           if(!st.empty() && st.top().second<value) st.push({value,st.top().second}); // already a min exists
           else st.push({value,value}); // stack empty or curr value was minimum
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            return st.top().first;
        }
        
        int getMin() {
            return st.top().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(value);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */