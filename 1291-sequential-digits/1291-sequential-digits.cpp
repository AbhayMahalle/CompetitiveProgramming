class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(char i='1'; i<='9'; i++){
            string num = "";
            for(char j=i; j<='9'; j++){
                num += j;
                int n = stoi(num);
                if(n>=low && n<=high){
                    res.push_back(n);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};