class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        int n = s.size();
        unordered_map<string, string> mp;
        for(auto k : knowledge){
            mp[k[0]] = k[1];
        }
        string key = "";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                i++;
                while(s[i]!=')')
                    key += s[i++];
            }
            if(!key.empty()){
                string cur = mp[key];
                if(!cur.empty()) res.append(cur.begin(), cur.end());
                else res += '?';
            }
            else res += s[i];
            key = "";
        }
        return res;
    }
};