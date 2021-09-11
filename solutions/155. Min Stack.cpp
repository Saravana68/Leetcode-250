class MinStack {
public:
    stack<long> st;
    long min =0;
    
    
    void push(int val) {
        
        if(st.empty())
        {
            st.push(0);
            min = val;
        }
        else
        {
            st.push(val-min);
            if(val<min)
                min = val;
        }
    }
    
    void pop() {
        
        if(st.top()<0) 
            min = min+ abs(st.top());
       st.pop();
    }
    
    int top() {
        if(st.top()<0) return min;
        else
            return (min + st.top());
    }
    
    int getMin() {
        return min;
    }
};
​
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
