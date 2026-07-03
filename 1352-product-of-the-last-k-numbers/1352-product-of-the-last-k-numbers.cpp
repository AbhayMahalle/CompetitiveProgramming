class ProductOfNumbers {
public:
    vector<long long> nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            nums.clear();
        }
        else if(!nums.empty()){
            nums.push_back(1LL*nums.back()*num);
        }
        else nums.push_back(num);
    }
    
    int getProduct(int k) {
        if(nums.empty() || nums.size()<k) return 0;
        else if(k==nums.size()) return nums.back();
        int n = nums.size();
        return nums.back()/nums[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */