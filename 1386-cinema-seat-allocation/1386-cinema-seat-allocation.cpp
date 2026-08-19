class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> bitMask;
        for(auto &r : reservedSeats){
            int i = r[0];
            int s = r[1]-1;
            bitMask[i] |= 1<<s;
        }
        int res = 0;
        for(auto &bit : bitMask){
            string cur = bitset<10>(bit.second).to_string();
            reverse(cur.begin(), cur.end());
            int a = 1, b = 1, c = 1;
            for(int i=2; i<=5; i++){
                if(cur[i-1]=='1') {
                    a = 0;
                    break;
                }
            }
            for(int i=4; i<=7; i++){
                if(cur[i-1]=='1') {
                    b = 0;
                    break;
                }
            }
            for(int i=6; i<=9; i++){
                if(cur[i-1]=='1') {
                    c = 0;
                    break;
                }
            }
            if((a && c)) res += 2;
            else if(a || b || c ) res++;
        }
        return res + (n-bitMask.size())*2;
    }
};