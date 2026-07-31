class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = 1;
        int n = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> vis;
        vis[beginWord] = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                string cur = q.front();
                q.pop();
                if(cur==endWord) return len;
                for(auto w : wordList){
                    if(vis.find(w)!=vis.end()){
                        continue;
                    }
                    int diff = 0;
                    for(int i=0; i<n; i++){
                        if(w[i]!=cur[i]) diff++;
                    }
                    if(diff==1){
                        vis[w] = 1;
                        q.push(w);
                    }
                }
            }
            len++;
        }
        return 0;
    }
};