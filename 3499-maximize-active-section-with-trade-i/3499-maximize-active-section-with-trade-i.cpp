class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int maxi = 0;
        for(char &c : s){
            if(c=='1') maxi++;
        }
        reverse(s.begin(), s.end());
        s.push_back('1');
        reverse(s.begin(), s.end());
        s.push_back('1');
        int i = 0;
        int block = -1;
        int prev = 0;
        int maxLen = 0;
        int len = -1;
        for(int j=1; j<s.size(); j++){
            if(s[j]=='1') prev = j; 
            if(block==-1 && s[j]=='1') continue;
            if(s[j]=='1'){
                if(len!=-1){
                    len += (j - block);
                    maxLen = max(len, maxLen);
                    len = (j - block);
                    block = -1;
                }
                else{
                    len = j - block;
                }
                block = -1;

            }
            else if(block==-1){
                block = j;
            }
        }
        cout << maxLen;
        return maxi + maxLen;

    }
};