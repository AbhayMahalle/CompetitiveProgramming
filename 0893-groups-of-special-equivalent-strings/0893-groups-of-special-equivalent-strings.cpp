class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st;
        for(auto &str : words){
            string odd = "", even = "";
            for(int i=0; i<str.size(); i++){
                if(i%2) odd+=str[i];
                else even+=str[i];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            even.append(odd.begin(), odd.end());
            str = even;
            st.insert(even);
        }
        return st.size();
    }
};