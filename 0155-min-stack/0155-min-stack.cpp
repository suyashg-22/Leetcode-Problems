class MinStack {
private:
    long long mini;
    stack<long long> st;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            mini = value;
            st.push(value);
        } else {
            if (value >= mini) {
                st.push(value);
            } else {
                // Push encoded value
                st.push(2 * value - mini);
                mini = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long topVal = st.top();
        st.pop();
        if (topVal < mini) {
            // Recover previous mini
            mini = 2 * mini - topVal;
        }
        if (st.empty()) {
            mini = LLONG_MAX; // Reset mini when stack becomes empty
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long topVal = st.top();
        if (topVal >= mini) return topVal;
        return mini;
    }

    int getMin() {
        return st.empty() ? -1 : mini;
    }
};
