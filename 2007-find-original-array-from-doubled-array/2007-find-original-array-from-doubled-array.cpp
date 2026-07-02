class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        int n = changed.size();
        vector<int> res;
        if(n%2) return res;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(changed[i]%2==0 && mp.count(changed[i]/2)){
                mp[changed[i]/2]--;
                if(mp[changed[i]/2]==0) mp.erase(changed[i]/2);
                res.push_back(changed[i]/2);
            }
            else mp[changed[i]]++;
        }
        if(!mp.empty()) return {};
        return res;
    }
};