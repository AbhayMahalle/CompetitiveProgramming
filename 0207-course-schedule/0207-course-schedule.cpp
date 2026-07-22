class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> mp;
        for(auto &p : pre){
            mp[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        vector<int> visited(n, false);
        queue<int> q;
        stack<int> st;
        for(int i=0; i<n ;i++){
            if(degree[i]==0){
                q.push(i);
                visited[i] = true;
                st.push(i);
            }
        }
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int f = q.front();
                q.pop();
                for(auto v : mp[f]){
                    degree[v]--;
                    if(degree[v]==0){
                        q.push(v);
                        st.push(v);
                    }
                }
            }
        }
        return st.size()==n;

    }
};