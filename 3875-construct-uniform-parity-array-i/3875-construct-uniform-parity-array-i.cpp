class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool odd = true, even = true;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0){
                // check for odd
                bool valid = false;
                for(int j=0; j<n; j++){
                    if(i!=j && abs(nums1[i]-nums1[j])%2==1){
                        valid = true;
                    }
                }
                if(!valid) odd = false;
            }
            else {
                // check for even
                bool valid = false;
                for(int j=0; j<n; j++){
                    if(i!=j && abs(nums1[i]-nums1[j])%2==0){
                        valid = true;
                    }
                }
                if(!valid) even = false;
            }
        }
        return odd | even;
    }
};