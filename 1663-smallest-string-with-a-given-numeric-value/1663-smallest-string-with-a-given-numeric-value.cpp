class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        for(int i=0; i<n; i++) 
            res += 'z';
        int total = n * 26;
        for(int i=0; i<n; i++){
            if(total-25>k){
                res[i] = 'a';
                total -= 25;
            }
            else{
                res[i] -= abs(total-k);
                break;
            }
        }
        return res;
    }
};