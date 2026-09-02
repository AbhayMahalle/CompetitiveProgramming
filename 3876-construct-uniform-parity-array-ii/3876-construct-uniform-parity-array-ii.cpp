class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool odd = true, even = true;
        int smallestEven = INT_MAX;
        int smallestOdd = INT_MAX;
        for(int num : nums1){
            if(num%2==0) smallestEven = min(smallestEven, num);
            else smallestOdd = min(smallestOdd, num);
        }
        if(smallestOdd==INT_MAX || smallestEven==INT_MAX) return true;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0){
                // check for odd
                if(!((nums1[i]-smallestOdd)>=1 && (nums1[i]-smallestOdd)%2==1)){
                    odd = false;
                }
            }
            else {
                // check for even
                if(!((nums1[i]-smallestEven)>=1 && (nums1[i]-smallestEven)%2==0)){
                    even = false;
                } 
            }
        }
        return odd | even;
    }
};