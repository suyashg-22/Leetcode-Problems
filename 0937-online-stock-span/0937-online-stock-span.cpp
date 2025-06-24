class StockSpanner {
public:
    stack<int>st;
    vector<int>arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int pge =0;
        while(!st.empty()&& arr[st.top()]<=price){
            st.pop();
        }
        if(st.empty()) pge =-1;
        else{
            pge = st.top();
        }
        st.push(arr.size()-1);

        return arr.size()-1-pge;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */