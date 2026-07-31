class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> freq;
        int n = word.size();
        for(int i=0; i<n; i+=k){
            string str = "";
            for(int j=i; j<i+k; j++){
                str += word[j];
            }
            freq[str]++;
        }
        int res = 0;
        int maxi = 0;
        for(auto &p: freq){
            int f = p.second;
            res += f;
            maxi = max(maxi, f);
        }
        return res - maxi;
    }
};