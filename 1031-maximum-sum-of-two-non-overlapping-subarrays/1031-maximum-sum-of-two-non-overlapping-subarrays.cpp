class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        int cur = 0;
        for(int i=0; i<n; i++){
            cur += nums[i];
            prefix[i] = cur;
        }
        int a = -1, b = -1, res = 0;
        int l = 0, r = 0;
        for(int i=0; i<n; i++){
            if(i+f-1<n){
                int sum = prefix[i+f-1];
                if(i-1>=0) sum -= prefix[i-1];
                a = sum;
                l = i, r = i+f-1;
                b = 0;
                for(int j=0; j<l; j++){
                    if(j+s-1<l){
                        int p = prefix[j+s-1];
                        if(j-1>=0) p -= prefix[j-1];
                        if(p>b){
                            b = p;
                        }
                    }
                }
                for(int j=r+1; j<n; j++){
                    if(j+s-1<n){
                        int p = prefix[j+s-1];
                        if(j-1>=0) p -= prefix[j-1];
                        if(p>b){
                            b = p;
                        }
                    }
                }
            }
            res = max(res, a+b);
        }
        return res;
    }
};