class MedianFinder {
private:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<>>mini;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxi.push(num);
        int x = maxi.top();
        maxi.pop();
        mini.push(x);
        if(mini.size()>maxi.size()){
            int y = mini.top();
            mini.pop();
            maxi.push(y);
        }
    }
    
    double findMedian() {
        double ans =maxi.top();
        if(maxi.size()==mini.size()){
            ans = ((double)maxi.top()+mini.top())/2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */