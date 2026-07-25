class Solution {
public:
    vector<int> segmentTree;
    void buildSegTree(int i, int l, int r, vector<int>& pairSum){
        if(l==r){
            segmentTree[i] = pairSum[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildSegTree(2*i+1, l, mid, pairSum);
        buildSegTree(2*i+2, mid+1, r, pairSum);
        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }
    void constructSegmentTree(int n, vector<int>& pairSum){
        segmentTree.resize(4*n, 0);
        buildSegTree(0, 0, n-1, pairSum);
    }
    int querySegTree(int st, int end, int i, int l, int r){
        if(l>end || r<st || st>end) return INT_MIN;
        if(st<=l && end>=r){
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        return max(querySegTree(st, end, 2*i+1, l, mid), querySegTree(st, end, 2*i+2, mid+1, r));
    }
    
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int> blockSize, start, endd, res;
        int activeSec = count(s.begin(), s.end(), '1');
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '0') {
                int st = i;
                while (i < s.size() && s[i] == '0') i++;
                start.push_back(st);
                endd.push_back(i - 1);
                blockSize.push_back(i-st);
            } else {
                i++;
            }
        }
        int n = blockSize.size()-1;
        if(n<=0) return vector<int>(queries.size(), activeSec);
        vector<int> pairSum;
        for(int i=1; i<=n; i++){
            pairSum.push_back(blockSize[i]+blockSize[i-1]);
        }
        constructSegmentTree(pairSum.size(), pairSum);
        for(auto &q : queries){
            int l = q[0], r = q[1];
            int last = upper_bound(start.begin(), start.end(), r) - start.begin() - 1;
            int first = lower_bound(endd.begin(), endd.end(), l) - endd.begin();
            int maxPairSum = 0;
            if(last>first){
                int firstLen = endd[first] - max(start[first], l) + 1;
                int lastLen =  min(r, endd[last]) - start[last] + 1;
                if(last-first!=1) {
                    maxPairSum = max(firstLen + blockSize[first+1], lastLen + blockSize[last-1]);
                    maxPairSum = max(querySegTree(first+1, last-2, 0, 0, n-1), maxPairSum);
                }
                else maxPairSum = firstLen + lastLen;
            }
            res.push_back(maxPairSum + activeSec);
            
        }
        
        return res;
    }
};