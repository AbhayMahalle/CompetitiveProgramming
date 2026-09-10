class Solution {
public:
    pair<int, int> trav(TreeNode* root, int& count){
        if(root==nullptr) return {0, 0};
        auto [leftSum, leftCnt] = trav(root->left, count);
        auto [rightSum, rightCnt] = trav(root->right, count);
        int curSum = leftSum + rightSum + root->val;
        int curCnt = leftCnt + rightCnt + 1;
        if(curSum/curCnt==root->val) count++;
        return {curSum, curCnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        trav(root, count);
        return count;
    }
};