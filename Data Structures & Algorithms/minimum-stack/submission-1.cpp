class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()) minSt.push(val);
        else if(minSt.top()>=val){
            minSt.push(val);
        }
        else return;
    }
    
    void pop() {
        if(minSt.top()==st.top()){
            st.pop();
            minSt.pop();
        }
        else st.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
