class Solution {
public:
    void update(int i, int l, int r, int idx, vector<int>& segTree){
        if(l==r){
            segTree[i]++;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid){
            update(2*i, l, mid, idx, segTree);
        }
        else {
            update(2*i+1, mid+1, r, idx, segTree);
        }
        segTree[i] = segTree[2*i] + segTree[2*i+1];
    }
    int query(int i, int ql, int qr, int l, int r, vector<int>& segTree){
        if(ql > r || l > qr) return 0;
        if(l>=ql && qr>=r) return segTree[i];
        int mid = l + (r-l)/2;
        return query(2*i, ql, qr, l, mid, segTree) + query(2*i+1, ql, qr, mid+1, r, segTree);
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            if(nums[i]%2){
                prefix[i+1] = prefix[i] + a;
            }
            else{
                prefix[i+1] = prefix[i] - b;
            }
        }
        vector<long long> pre = prefix;
        sort(pre.begin(), pre.end());
        pre.erase(unique(pre.begin(), pre.end()), pre.end());
        int m = pre.size();
        vector<int> segTree(m*4, 0);
        int idx = lower_bound(pre.begin(), pre.end(), prefix[0]) - pre.begin();
        update(1, 0, m-1, idx, segTree);
        long long res = 0;
        for(int i=1; i<=n; i++){
            idx = lower_bound(pre.begin(), pre.end(), prefix[i]) - pre.begin();
            res += query(1, 0, idx, 0, m-1, segTree);
            update(1, 0, m-1, idx, segTree);
        }
        return res;
    }
};