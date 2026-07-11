class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int> visited(n, false);
        unordered_map<int, vector<int>> mp;
        for(auto &e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        for(int i=0; i<n; i++){
            int c = 0;
            if(visited[i]) continue;
            int nodes = 1;
            visited[i] = true;
            queue<int> q;
            q.push(i);
            if(!(mp.find(i)!=mp.end())){
                cnt++;
                q.pop();
                continue;
            }
            while(!q.empty()){
                int s = q.size();
                while(s--){
                    int cur = q.front();
                    q.pop();
                    for(int t : mp[cur]){
                        c++;
                        if(visited[t]) continue;
                        q.push(t);
                        nodes++;
                        visited[t] = true;
                    }
                }
            }
            c /= 2;
           if (c==nodes*(nodes-1)/2) cnt++;
        }
        return cnt;
    }
};