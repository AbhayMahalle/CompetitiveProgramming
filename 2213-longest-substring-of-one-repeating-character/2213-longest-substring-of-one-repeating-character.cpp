class Solution {
public:
    class node {
    public:
        int maxLen;
        char leftMostChar;
        char rightMostChar;
        int prefixLen;
        int suffixLen;

        node(){
            maxLen = 0;
            leftMostChar = '/';
            rightMostChar = '/';
            prefixLen = 0;
            suffixLen = 0;
        }
    };
    void buildSegTree(int i, int l, int r, string& s, vector<node>& segTree){
        if(l==r){
            segTree[i].maxLen = 1;
            segTree[i].leftMostChar = s[l];
            segTree[i].rightMostChar = s[r];
            segTree[i].prefixLen = 1;
            segTree[i].suffixLen = 1;
            return;
        }
        int mid = l + (r-l)/2;
        buildSegTree(2*i+1, l, mid, s, segTree);
        buildSegTree(2*i+2, mid+1, r, s, segTree);
        node left = segTree[2*i+1];
        node right = segTree[2*i+2];
        segTree[i].leftMostChar = left.leftMostChar;
        segTree[i].rightMostChar = right.rightMostChar;
        if(left.rightMostChar!=right.leftMostChar){
            segTree[i].maxLen = max(left.maxLen, right.maxLen);
            segTree[i].prefixLen = left.prefixLen;
            segTree[i].suffixLen = right.suffixLen;
        }
        else {
            segTree[i].maxLen = max({left.maxLen, right.maxLen, left.suffixLen+right.prefixLen});
            if(left.suffixLen==(mid-l+1) && right.prefixLen==(r-(mid+1)+1)) {
                segTree[i].prefixLen = left.suffixLen+right.prefixLen;
                segTree[i].suffixLen = left.suffixLen+right.prefixLen;
            }
            else if(left.suffixLen==(mid-l+1)){
                segTree[i].prefixLen = left.suffixLen + right.prefixLen;
                segTree[i].suffixLen = right.suffixLen;
            }
            else if(right.prefixLen==(r-(mid+1)+1)){
                segTree[i].prefixLen = left.prefixLen;
                segTree[i].suffixLen = left.suffixLen + right.prefixLen;
            }
            else{
                segTree[i].prefixLen = left.prefixLen;
                segTree[i].suffixLen = right.suffixLen;
            }
        }
    }
    void update(int i, int l, int r, int idx, char c, string& s, vector<node>& segTree){
        if(l==r){
            segTree[i].maxLen = 1;
            segTree[i].leftMostChar = c;
            segTree[i].rightMostChar = c;
            segTree[i].prefixLen = 1;
            segTree[i].suffixLen = 1;
            s[idx] = c;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid){
            update(2*i+1, l, mid, idx, c, s, segTree);
        }
        else {
            update(2*i+2, mid+1, r, idx, c, s, segTree);
        }
        node left = segTree[2*i+1];
        node right = segTree[2*i+2];
        segTree[i].leftMostChar = left.leftMostChar;
        segTree[i].rightMostChar = right.rightMostChar;
        if(left.rightMostChar!=right.leftMostChar){
            segTree[i].maxLen = max(left.maxLen, right.maxLen);
            segTree[i].prefixLen = left.prefixLen;
            segTree[i].suffixLen = right.suffixLen;
        }
        else {
            segTree[i].maxLen = max({left.maxLen, right.maxLen, left.suffixLen+right.prefixLen});
            if(left.suffixLen==(mid-l+1) && right.prefixLen==(r-(mid+1)+1)) {
                segTree[i].prefixLen = left.suffixLen+right.prefixLen;
                segTree[i].suffixLen = left.suffixLen+right.prefixLen;
            }
            else if(left.suffixLen==(mid-l+1)){
                segTree[i].prefixLen = left.suffixLen + right.prefixLen;
                segTree[i].suffixLen = right.suffixLen;
            }
            else if(right.prefixLen==(r-(mid+1)+1)){
                segTree[i].prefixLen = left.prefixLen;
                segTree[i].suffixLen = left.suffixLen + right.prefixLen;
            }
            else{
                segTree[i].prefixLen = left.prefixLen;
                segTree[i].suffixLen = right.suffixLen;
            }
        }
    }
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        vector<node> segTree(4*n, node());
        buildSegTree(0, 0, n-1, s, segTree);
        vector<int> res;
        for(int i=0; i<qc.size(); i++){
            update(0, 0, n-1, qi[i], qc[i], s, segTree);
            res.push_back(segTree[0].maxLen);
        }
        return res;
    }
};