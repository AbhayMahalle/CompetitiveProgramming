class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string shortestBeautiful = "";
        int n = s.size();
        int i = 0, j = 0;
        int oneCnt = 0;
        for(int i=0; i<n; i++){
            oneCnt = 0;
            string curStr = "";
            for(int j=i; j<n; j++){
                curStr += s[j];
                if(s[j]=='1') oneCnt++;
                if(oneCnt>k || (shortestBeautiful != "" && shortestBeautiful.size()<curStr.size())) break;
                if(oneCnt==k){
                    if(shortestBeautiful.size()==curStr.size()) {
                        shortestBeautiful = min(shortestBeautiful, curStr);
                    }
                    else shortestBeautiful = curStr;
                }
            }
        }
        return shortestBeautiful;
    }  
};