/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generate(int n, int l, int r){
        if(n==0){
            return {nullptr};
        }
        if(n==1){
            return {new TreeNode(l)};
        }
        vector<TreeNode*> res;
        for(int i=l; i<=r; i++){
            auto left = generate(i-l, l, i-1);
            auto right = generate(r-i, i+1, r);
            for(auto ll : left){
                for(auto rr : right){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = ll;
                    cur->right = rr;
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(n, 1, n);
    }
};