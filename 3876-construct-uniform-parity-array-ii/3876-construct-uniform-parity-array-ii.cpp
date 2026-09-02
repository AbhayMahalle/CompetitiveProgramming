class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool canMakeOdd = true;
        bool canMakeEven = true;

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
                if(!((nums1[i]-smallestOdd)>=1 &&
                     (nums1[i]-smallestOdd)%2==1)){
                    canMakeOdd = false;
                }
            }
            else {
                // check for even
                if(!((nums1[i]-smallestEven)>=1 &&
                     (nums1[i]-smallestEven)%2==0)){
                    canMakeEven = false;
                }
            }
            if(canMakeEven==false && canMakeOdd==false) return false;
        }
        return true;
    }
};