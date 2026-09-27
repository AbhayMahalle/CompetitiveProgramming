class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        while(true){
            int r = s.find(')');
            if(r == string::npos){
                break;
            }
            int l = s.rfind('(', r);
            s[l] = '.';
            s[r] = '.';
            while(l<r){
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        erase(s, '.');
        return s;
    }
};