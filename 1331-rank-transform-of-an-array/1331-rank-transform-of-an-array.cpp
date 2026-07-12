class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<int> res = arr;
        unordered_map<int, int> mp;
        sort(res.begin(), res.end());
        int prev = res[0];
        int r = 1;
        for(int i=0; i<n ;i++){
            if(prev==res[i]){
                mp[res[i]] = r;
            }
            else{
                r++;
                mp[res[i]] = r;
            }
            prev = res[i];
        }
        n = arr.size();
        for(int i=0; i<n ;i++){
            res[i] = mp[arr[i]];
        }
        return res;
    }
};