class Solution {
public:
    void dfs(string curWord, int lvl, unordered_map<string, int> &mp, vector<string> &v, vector<vector<string>>& res){
        if(lvl==0){
            res.push_back(v);
            return;
        }
        int n = curWord.size();
        int t = lvl-1;
        for(int i=0; i<n; i++){
            string s = curWord;
            for(char c='a'; c<='z'; c++){
                s[i] = c;
                if(mp.find(s)!=mp.end() && mp[s]==t){
                    v.push_back(s);
                    dfs(s, t, mp, v, res);
                    v.pop_back();
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_map<string, int> mp;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> st(wordList.begin(), wordList.end());
        int lvl = 0;
        mp[beginWord] = 0;
        while(!q.empty()){
            int s = q.size();
            unordered_set<string> used;
            while(s--){
                string cur = q.front();
                lvl = mp[cur];
                q.pop();
                string temp;
                for(int i=0; i<n; i++){
                    temp = cur;
                    for(char c='a'; c<='z'; c++){
                        temp[i] = c;
                        if(st.find(temp)!=st.end() && !(mp.find(temp)!=mp.end())){
                            used.insert(temp);
                            mp[temp] = lvl+1;
                            q.push(temp);
                        }
                    }
                }
            }
            for(auto &x: used){
                st.erase(x);
            }
        }
        vector<vector<string>> res;
        vector<string> v;
        if(mp.find(endWord)!=mp.end()) {
            v.push_back(endWord);
            dfs(endWord, mp[endWord], mp, v, res);
            for(auto &v : res){
                reverse(v.begin(), v.end());
            }
        }
        return res;
    }
};