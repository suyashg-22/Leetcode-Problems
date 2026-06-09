class Node{
private:
    vector<Node*>arr;
    bool flag;
public:
    Node(){
        this->arr.assign(26,NULL);
        this->flag=false;
    }

    bool contain(char ch){
        return !(arr[ch-'a']==NULL);
    }

    Node* next(char ch){
        return  arr[ch-'a'];
    }

    void assign(char ch){
        Node* nnode = new Node();
        this->arr[ch-'a']=nnode;
    }

    void modflag(bool f){
        this->flag = f;
    }

    bool getflag(){
        return this->flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }
    
    void insert(string word) {
        int n =word.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            char ch = word[i];
            if(node->contain(ch)){
                node= node->next(ch);
            }
            else{
                node->assign(ch);
                node=node->next(ch);
            }

        }
        node->modflag(true);
    }
    
    bool search(string word) {
        int n = word.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            char ch = word[i];
            if(!node->contain(ch))return false;
            node= node->next(ch);
        }
        return (node->getflag()==true);
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* node = root;
        for(int i=0;i<n;i++){
            char ch = prefix[i];
            if(!node->contain(ch))return false;
            node=node->next(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */