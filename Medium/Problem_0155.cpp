class MinStack {
    stack<pair<int, int>> st; // Stack to store pairs of (value, current_min)
public:
    MinStack() {}

    void push(int val) {
        // If the stack is empty, the current minimum is the value itself
        int currentMin = st.empty() ? val : std::min(st.top().second, val);
        st.push({val, currentMin});
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        if (!st.empty()) {
            return st.top().first;
        }
        throw runtime_error("Stack is empty");
    }
    
    int getMin() {
        if (!st.empty()) {
            return st.top().second;
        }
        throw runtime_error("Stack is empty");
    }
};
