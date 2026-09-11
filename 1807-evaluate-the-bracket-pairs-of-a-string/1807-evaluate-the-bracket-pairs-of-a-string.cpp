class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        int n = s.size();
        bool inBracket = false;
        unordered_map<string, string> mp;
        for(auto k : knowledge){
            mp[k[0]] = k[1];
        }
        string key = "";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                inBracket = true;
                continue;
            }
            else if(s[i]==')'){
                inBracket = false;
            }
            if(inBracket){
                key += s[i];
            }
            else{
                if(!key.empty()){
                    auto cur = mp[key];
                    if(!cur.empty()) res.append(cur.begin(), cur.end());
                    else res.push_back('?');
                }
                else res += s[i];
                key = "";
            }
        }
        return res;
    }
};