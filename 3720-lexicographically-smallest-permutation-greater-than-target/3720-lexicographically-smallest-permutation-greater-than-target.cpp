class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans = "";
        sort(s.begin(), s.end());
        int n = s.size();
        string pre = "";
        for(int i=0; i<n; i++){
            int lb = lower_bound(s.begin(), s.end(), target[i]) - s.begin();
            int ub = upper_bound(s.begin(), s.end(), target[i]) - s.begin();
            if(lb==s.size()) break;
            string cur = pre;
            string temp = s;
            if(s[lb]!=target[i]){
                cur += s[lb];
                s.erase(s.begin()+lb);
                cur.append(s.begin(), s.end());
                if(ans!="") ans = min(ans, cur);
                else ans = cur;
                break;
            }
            else if(ub!=s.size()){
                cur += temp[ub];
                temp.erase(temp.begin()+ub);
                cur.append(temp.begin(), temp.end());
                if(ans!="") ans = min(ans, cur);
                else ans = cur;
            }
            pre += s[lb];
            s.erase(s.begin()+lb);
        }
        return ans==target? "" : ans;
    }
};