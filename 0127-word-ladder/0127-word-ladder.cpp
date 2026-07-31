class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = 1;
        int n = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                string cur = q.front();
                q.pop();
                if(cur==endWord) return len;
                string s = cur;
                for(int i=0; i<n; i++){
                    s = cur;
                    for(char c='a'; c<='z'; c++){
                        s[i] = c;
                        if(st.find(s)!=st.end()){
                            st.erase(s);
                            q.push(s);
                        }
                    }
                }
            }
            len++;
        }
        return 0;
    }
};