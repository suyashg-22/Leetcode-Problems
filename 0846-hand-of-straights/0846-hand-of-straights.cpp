class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto h:hand)pq.push(h);
        
        while(!pq.empty()){
            vector<int>temp;
            int g=0;
            int last =-1;
            while(g<groupSize && !pq.empty()){
                if(g==0){
                    last = pq.top();
                    pq.pop();
                    g+=1;
                }
                else{
                    while(!pq.empty() && pq.top()==last){
                        temp.push_back(pq.top());
                        pq.pop();
                    }
                    if(pq.empty())return false;
                    if(pq.top()>last+1)return false;
                    last=pq.top();
                    pq.pop();
                    g+=1;
                }
            }
            if(g<groupSize)return false;
            for(auto t:temp)pq.push(t);
        }
        return true;
    }
};