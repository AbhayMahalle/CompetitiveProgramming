class Solution {
public:
    vector<int> solve(string s){
        vector<int> ans;
        int n = s.size();
        if(n==0) return ans;
        if(n==1) return {stoi(s)};
        int isThere = false;
        for(int i=0; i<n; i++){
            if(s[i]=='-' || s[i]=='+' || s[i]=='*'){
                isThere = true;
                auto left = solve(s.substr(0, i));
                auto right = solve(s.substr(i+1));
                for(int l : left){
                    for(int r :right){
                        if(s[i]=='-'){
                            ans.push_back(l-r);
                        }
                        else if(s[i]=='+'){
                            ans.push_back(l+r);
                        }
                        else {
                            ans.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(!isThere) ans.push_back(stoi(s));
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};