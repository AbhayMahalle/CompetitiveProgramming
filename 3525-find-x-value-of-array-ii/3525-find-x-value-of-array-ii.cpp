class Solution {
public:
    struct Node{
        int prod;
        array<int, 5> count;
        Node(){
            prod = 1;
            count.fill(0);
        }
    };
    vector<Node> segTree;
    int k;
    Node mergeNode(const auto&left, const auto&right){
        int leftProd = left.prod;
        const auto& leftCnt = left.count;
        const auto& rightCnt = right.count;
        Node res;
        res.prod = (left.prod * right.prod) % k;
        for(int i=0; i<k; i++){
            res.count[i] += leftCnt[i];
        }
        for(int i=0; i<k; i++){
            if(rightCnt[i]==0) continue;
            int newProd = (i*leftProd)%k;
            res.count[newProd] += rightCnt[i];
        }
        return res;
    }
    void buildSegTree(int i, int l, int r, auto&nums){
        if(l==r){
            segTree[i].prod = nums[l];
            segTree[i].count[nums[l]%k]++;
            return;
        }
        int mid = l+(r-l)/2;
        buildSegTree(2*i+1, l, mid, nums);
        buildSegTree(2*i+2, mid+1, r, nums);
        segTree[i] = mergeNode(segTree[2*i+1], segTree[2*i+2]);
    }
    void update(int i, int l, int r, int idx, int val, auto&nums){
        if(l==r && idx==l){
            nums[l] = val;
            segTree[i].prod = nums[l];
            segTree[i].count.fill(0);
            segTree[i].count[nums[l]%k]++;
            return;
        }
        int mid = l+(r-l)/2;
        if(idx<=mid) update(2*i+1, l, mid, idx, val, nums);
        else update(2*i+2, mid+1, r, idx, val, nums);
        segTree[i] = mergeNode(segTree[2*i+1], segTree[2*i+2]);
    }
    Node query(int i, int l, int r, int start, int end){
        if(start<=l && r<=end) return segTree[i];
        int mid = l + (r-l) / 2;
        if(end<=mid){
            return query(2*i+1, l, mid, start, end);
        }
        else if(start>mid){
            return query(2*i+2, mid+1, r, start, end);
        }
        Node left = query(2*i+1, l, mid, start, end);
        Node right = query(2*i+2, mid+1, r, start, end);
        return mergeNode(left, right);
    }
    
public:
    vector<int> resultArray(vector<int>& nums, int kk, vector<vector<int>>& queries) {
        k = kk;
        int n = nums.size();
        for(auto &num : nums) num %= k;
        segTree.resize(4*n);
        buildSegTree(0, 0, n-1, nums);
        vector<int> res;
        res.reserve(queries.size());
        for(auto &q : queries){
            int idx = q[0];
            int val = q[1]%k;
            int start = q[2];
            int x = q[3];
            update(0, 0, n-1, idx, val, nums);
            Node cur = query(0, 0, n-1, start, n-1);
            res.push_back(cur.count[x%k]);
        }
        return res;
    }
};