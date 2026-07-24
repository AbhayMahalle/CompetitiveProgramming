class Solution {
public:
    int n = 50000;
    vector<int> segmentTree;
    void constructSegmentTree(){
        segmentTree.resize(4*n, 0);
    }
    void updateSegmentTree(int idx, int val, int i, int l, int r){
        if(l==r){
            segmentTree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid){
            updateSegmentTree(idx, val, 2*i+1, l, mid);
        }
        else{
            updateSegmentTree(idx, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }
    int querySegmentTree(int start, int end, int i, int l, int r){
        if(l>end || r<start) return 0;
        if(l>=start && r<=end){
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        return max(querySegmentTree(start, end, 2*i+1, l, mid), querySegmentTree(start, end, 2*i+2, mid+1, r));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        constructSegmentTree();
        set<int> obstacles;
        obstacles.insert(0);
        vector<bool> res;
        for(auto &q : queries){
            int x = q[1];
            if(q[0]==1){
                auto it = obstacles.upper_bound(x);
                int nxt = (it != obstacles.end()) ? *it : -1;
                int pre = *prev(it);
                updateSegmentTree(x, x-pre, 0, 0, n-1);
                updateSegmentTree(nxt, nxt-x, 0, 0, n-1);
                obstacles.insert(x);
            }
            else{
                int sz = q[2];
                auto it = obstacles.upper_bound(x);
                int pre = *prev(it);
                int maxGap = querySegmentTree(0, pre, 0, 0, n-1);
                maxGap = max(maxGap, x-pre);
                res.push_back((maxGap>=sz));
            }
        }
        return res;
    }
};