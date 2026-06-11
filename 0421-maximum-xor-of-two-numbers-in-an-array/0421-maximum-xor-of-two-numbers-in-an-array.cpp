class Node{
public:
    Node* arr[2];
    Node(){
        arr[0]=NULL;
        arr[1]=NULL;
    }
    ~Node(){
        delete arr[0];
        delete arr[1];
    }
    Node* next(int i){
        return arr[i];
    }
    bool isempty(int i){
        return arr[i]==NULL;
    }

};
class Trie{
public:
    Node* root;
    Trie(){
        root= new Node();
    }
    ~Trie(){
        delete root;
    }
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int b = (num>>i)&1;
            if(node->isempty(b)){
                Node* nnode = new Node();
                node->arr[b]=nnode;
            }
            node=node->next(b);
        }
    }
    int maxixor(int num){
        int ans =0;
        Node* node =root;
        for(int i=31;i>=0;i--){
            int b = (num>>i)&1;
            if(b==0 && !node->isempty(1)){
                int temp = (1<<i);
                ans+=temp;
                node=node->next(1);
            }
            else if(b==1 && !node->isempty(0)){
                int temp = (1<<i);
                ans+=temp;
                node=node->next(0);
            }
            else{
                node=node->next(b);
            }
        }
        return ans;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n= nums.size();
        Trie* t = new Trie();
        for(auto x:nums){
            t->insert(x);
        }
        int maxi =0;
        for(auto x:nums){
            maxi=max(maxi,t->maxixor(x));
        }
        return maxi;
    }
};