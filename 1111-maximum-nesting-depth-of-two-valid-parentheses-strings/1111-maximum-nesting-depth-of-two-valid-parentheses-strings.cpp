class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        return solve(seq);
    }
    vector<int> solve(string seq) {
    vector<int> ans(seq.size());
    int depth = 0;

    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] == '(') {
            ans[i] = depth % 2;
            depth++;
        } else {
            depth--;
            ans[i] = depth % 2;
        }
    }

    return ans;
}
};