class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mx = 0;
        int d = 0;
        for(char c : s){
            if(c=='('){
                st.push('(');
                d++;
            }
            else if(c==')'){
                mx = max(d, mx);
                d--;
            }
        }
        return mx;
    }
};