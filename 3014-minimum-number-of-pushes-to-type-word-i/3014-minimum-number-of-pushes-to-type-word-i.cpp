class Solution {
public:
    int minimumPushes(string word) {
        int len = word.size();
        int cur = 1;
        int res = 0;
        while(len){
            if(len/8){
                res += (cur*8);
                len -= 8;
                cur++;
            }
            else {
                res += (cur*len);
                len = 0;
            }
        }
        return res;
    }
};