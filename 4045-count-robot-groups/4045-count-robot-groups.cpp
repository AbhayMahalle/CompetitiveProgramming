class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int dist) {
        stack<pair<int, int>> st;
        int n = position.size();
        for(int i=n-1; i>=0; i--){
            if(!st.empty() && (st.top().first-position[i]<=dist || st.top().second<speed[i])){
                int spd = st.top().second;
                st.pop();
                st.push({position[i], spd});
            }
            else st.push({position[i], speed[i]});
        }
        return st.size();
    }
};