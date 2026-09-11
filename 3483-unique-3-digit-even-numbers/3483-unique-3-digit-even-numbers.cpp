class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        int cnt = 0;
        for(int d : digits) freq[d]++;
        for(int i=1; i<=9; i++){
            if(freq[i]==0) continue;
            freq[i]--;
            for(int j=0; j<=9; j++){
                if(freq[j]==0) continue;
                freq[j]--;
                for(int k=0; k<9; k+=2){
                    if(freq[k]>0) cnt++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return cnt;
    }
};