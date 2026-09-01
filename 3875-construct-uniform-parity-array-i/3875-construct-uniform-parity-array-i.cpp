class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        // try for all even
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0) nums1.push_back(nums1[i]);
            else{
                bool valid = false;
                for(int j=0; j<n; j++){
                    if(i!=j && abs(nums1[i]-nums1[j])%2==0){
                        valid = true;
                    }
                }
                if(!valid) break;
            }
            if(i==n-1) return true;
        }
        // try for all odd
        for(int i=0; i<n; i++){
            if(nums1[i]%2==1) nums1.push_back(nums1[i]);
            else{
                bool valid = false;
                for(int j=0; j<n; j++){
                    if(i!=j && abs(nums1[i]-nums1[j])%2==1){
                        valid = true;
                    }
                }
                if(!valid) break;
            }
            if(i==n-1) return true;
        }
        return false;
    }
};