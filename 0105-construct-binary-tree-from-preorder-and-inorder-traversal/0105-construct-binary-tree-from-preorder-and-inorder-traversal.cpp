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
    int idx = 0;
    unordered_map<int, int> mp;
    TreeNode* solve(auto & preorder, int st, int end){
        if(st>end) return nullptr;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        int mid = mp[val];
        root->left = solve(preorder, st, mid-1);
        root->right = solve(preorder, mid+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        return solve(preorder, 0, inorder.size()-1);
    }
};