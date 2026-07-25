class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int, int> mp;
        for(int n : a) mp[n]++;
        int res = 0;
        for(auto &p : mp){
            int cur = p.first;
            int freq = p.second;
            if(cur==0) res += freq;
            else {
                int a = (freq/(cur+1)) + (freq%(cur+1)!=0);
                res += (a*cur) + a;
            }
        }
        return res;
    }
};  