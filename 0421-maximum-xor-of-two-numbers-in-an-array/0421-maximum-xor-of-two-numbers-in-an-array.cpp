class Node{
public:
    vector<Node*>arr;
    Node(){
        arr.assign(2,NULL);
    }
    Node* next(char ch){
        return arr[ch-'0'];
    }
    bool isempty(char ch){
        return arr[ch-'0']==NULL;
    }

};
class Trie{
public:
    Node* root;
    Trie(){
        root= new Node();
    }
    void insert(string &s){
        Node* node = root;
        for(auto ch:s){
            if(node->isempty(ch)){
                Node* nnode = new Node();
                node->arr[ch-'0']=nnode;
            }
            node=node->next(ch);
        }
    }
    int maxixor(string &s){
        int ans =0;
        Node* node =root;
        for(int i=0;i<32;i++){
            char ch = s[i];
            if(ch=='0' && !node->isempty('1')){
                int temp = (1<<(31-i));
                ans+=temp;
                node=node->next('1');
            }
            else if(ch=='1' && !node->isempty('0')){
                int temp = (1<<(31-i));
                ans+=temp;
                node=node->next('0');
            }
            else{
                node=node->next(ch);
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
            string s = bitset<32>(x).to_string();
            t->insert(s);
        }
        int maxi =0;
        for(auto x:nums){
            string s = bitset<32>(x).to_string();
            maxi=max(maxi,t->maxixor(s));
        }
        return maxi;
    }
};