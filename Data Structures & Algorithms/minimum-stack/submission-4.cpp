class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min_st.push(val);
        }
        else if(val>min_st.top()){
            st.push(val);
        }
        else{
            st.push(val);
            min_st.push(val);
        }
    }
    
    void pop() {
        // if(st.empty() || min_st.empty()){
        //     return ;
        // }
        if(st.top()==min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        // if(st.empty()){
        //     return -1;
        // }
        return st.top();
    }
    
    int getMin() {
        // if(min_st.empty()){
        //     return -1;
        // }
        return min_st.top();
    }
};
