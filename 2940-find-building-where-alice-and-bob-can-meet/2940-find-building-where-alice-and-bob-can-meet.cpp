class Solution {
public:
    void buildSegTree(int i, int l, int r, vector<int>& segTree, vector<int>& heights){
        if(l==r){
            segTree[i] = heights[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildSegTree(2*i+1, l, mid, segTree, heights);
        buildSegTree(2*i+2, mid+1, r, segTree, heights);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }
    int query(int i, int ql, int qr, int l, int r, vector<int>& segTree){
        if(ql>r || qr<l) return INT_MIN;
        if(l>=ql && qr>=r){
            return segTree[i];
        }
        int mid = l + (r-l)/2;
        int left = query(2*i+1, ql, qr, l, mid, segTree);
        int right = query(2*i+2, ql, qr, mid+1, r, segTree);
        return max(left, right);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segTree(4*n, 0);
        buildSegTree(0, 0, n-1, segTree, heights);
        vector<int> res;
        for(auto &q : queries){
            int l = min(q[0], q[1]);
            int r = max(q[0], q[1]);
            if(l==r || heights[r]>heights[l]){
                res.push_back(r);
                continue;
            }
            int curRes = -1;
            int target = max(heights[l],heights[r]);
            l = r+1, r = n-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                int left = query(0, l, mid, 0, n-1, segTree);
                if(left>target){
                    curRes = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            res.push_back(curRes);
        }
        return res;
    }
};