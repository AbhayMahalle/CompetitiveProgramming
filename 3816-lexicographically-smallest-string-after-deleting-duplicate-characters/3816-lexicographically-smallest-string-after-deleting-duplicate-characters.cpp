class Solution {
public:
    string lexSmallestAfterDeletion(string str) {
        unordered_map<char, int> freq, taken;
        for(char &c : str) freq[c]++;
        string s = "";
        for(char &c : str){
            freq[c]--;
            if(!s.empty() && s.back()>c && (taken[s.back()]>1 || freq[s.back()]>=1)){
                while(!s.empty() && s.back()>c && (taken[s.back()]>1 || freq[s.back()]>=1)){
                    taken[s.back()]--;
                    s.pop_back();
                }
                s.push_back(c);
                taken[c]++;
            }
            else {
                s.push_back(c);
                taken[c]++;
            }
        }
        while(taken[s.back()]>1) {
            taken[s.back()]--;
            s.pop_back();

        }
        return s;
    }
};