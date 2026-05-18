class Solution {
public:

    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }    

        queue<pair<int,int>>q;
        vector<int>vis(n,0);
        q.push({0,0});
        vis[0]=1;
        int ans=1e9;

        while(!q.empty()){
                auto it = q.front();
                q.pop();
                int ind = it.first;
                int d = it.second;
                if(ind==n-1){
                    ans=d;
                    break;
                }

                if(ind-1>=0 && !vis[ind-1]){
                    q.push({ind-1,d+1});
                    vis[ind-1]=1;    
                }
                if(ind+1<n && !vis[ind+1]){
                    q.push({ind+1,d+1});
                    vis[ind+1]=1;
                }
                for(auto in:mpp[arr[ind]]){
                    if(in!=ind){
                        if(!vis[in]){
                            q.push({in,d+1});
                            vis[in]=1;
                        }
                    }
                }
                mpp.erase(arr[ind]);
    
        }
        return ans;
    }
};