class Solution {
    vector<string> ans;
    void dfs(string s) {
        int r = s.find('}');
        if(r == string::npos){
            ans.push_back(s);
            return;
        }

        int l = s.rfind('{', r);

        string left = s.substr(0, l);
        string right = s.substr(r + 1);

        string inside = s.substr(l + 1, r - l - 1);

        string part;
        stringstream ss(inside);

        while(getline(ss, part, ',')){
            dfs(left + part + right);
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();