class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        string s = to_string(n);
        for(int i=0; i<s.size(); i++){
            string digit = "";
            digit += s[i];
            int d = stoi(digit);
            if(d){
                sum += d;
                num = num*10 + d;
            }
        }
        return 1LL*sum*num;
    }
};