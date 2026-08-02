class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        int ans = 1;
        unordered_map<int, int> freq, pair;
        for(int p : planks){
            freq[p]++;
            ans = max(ans, freq[p]);
        }
        vector<int> unique;
        for(auto p : freq){
            unique.push_back(p.first);
        }
        for(int i=0; i<unique.size(); i++){
            pair[2*unique[i]] += freq[unique[i]]/2;
            ans = max(ans, pair[2*unique[i]]);
            for(int j=i+1; j<unique.size(); j++){
                pair[unique[i]+unique[j]] += min(freq[unique[i]], freq[unique[j]]);
                ans = max(ans, pair[unique[i]+unique[j]]);
            }
        }
        for(auto &p : freq){
            int cur = p.second;
            if(pair.find(p.first)!=pair.end()){
                cur += pair[p.first];
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};