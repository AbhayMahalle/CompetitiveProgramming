class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> freq;
        int mx = 0;
        for(auto &v : responses){
            unordered_map<string, int> mp;
            for(auto &s : v){
                mp[s] = 1;
            }
            for(auto &p : mp){
                freq[p.first]++;
                mx = max(mx, freq[p.first]);
            }
        }
        string res = "";
        for(auto &p : freq){
            if(p.second==mx){
                res = p.first;
                break;
            }
        }
        return res;
    }
};