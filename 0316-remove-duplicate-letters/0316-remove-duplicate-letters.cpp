class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int> freq, taken;
        for(int i=n-1; i>=0; i--){
           freq[s[i]]++; 
        }
        string st = "";
        for(char c : s){
            freq[c]--;
            if(st.size()==0) {
                st.push_back(c);
                taken[c]++;
            }
            else if(st.back()>c && taken.count(c)==0){
                while(!st.empty() && st.back()>c && freq[st.back()]){
                    taken.erase(st.back());
                    st.pop_back();
                }
                st.push_back(c);
                taken[c]++;
            } 
            else if(taken.count(c)==0){
                st.push_back(c);
                taken[c]++;
            }

        }
        return st;
    }
};