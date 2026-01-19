#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 1000000009;

#define asc(x) (x).begin(), (x).end()
#define desc(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i, a, b) for (int i = (a); i < (b); i++)
#define fore(x, a) for (auto& x : a)
#define yes cout << "YES\n"
#define no cout << "NO\n"
// #define endl '\n'

class Solution {
public:
    string s1;
    string s2;
    int n;
    vector<string>* arr;
    unordered_set<string> st;

    int bfs() {
        // prereq-*adj,n,ans,vis

        // vector<pair<int, int>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        queue<pair<string, int>> q;
        // starting push and mark it vis:
        q.push({s1, 1});
        st.erase(s1);

        // logic:
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            string s = p.ff;
            int d = p.ss;

            
            for (int i = 0; i < s.size(); i++) {

                for (char c = 'a'; c <= 'z'; c++) {
                    string temp = s;
                    temp[i]=c;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,d+1});
                        if (temp == s2)return d+1;
                    }
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        this->s1 = beginWord;
        this->s2 = endWord;
        this->n = wordList.size();
        this->arr = &wordList;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(wordList[i]==s1)flag = true;
            st.insert(wordList[i]);
        }
        if(!flag)st.insert(s1);
        return bfs();
    }
};