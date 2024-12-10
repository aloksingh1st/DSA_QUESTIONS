class MinStack {
      int minele=INT_MAX;
    stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
     void push(int val) {
        if(!st.empty()) minele = min((st.top()).second, val);
        else minele = val;
        st.push({val,minele});
    }
    
    void pop() {
        st.pop();
        if(st.empty()) minele=INT_MAX;
    }
    
    int top() {
        return (st.top()).first;
    }
    
    int getMin() {
         if(st.empty()) return NULL;
        return (st.top()).second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */