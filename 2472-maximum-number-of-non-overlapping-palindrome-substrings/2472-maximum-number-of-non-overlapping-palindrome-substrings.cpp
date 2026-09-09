class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k==1) return n;
        vector<pair<int, int>> ranges(n, {-1, -1});
        vector<bool> find(n, false);
        for(int i=0; i<n; i++){
            int l = i-1, r = i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if(r-l+1>=k){
                        if(find[l]) break;
                        ranges[l] = {l, r};
                        find[l] = true;
                        break;
                    }
                    l--;
                    r++;
                }
                else break;
            }
            l = i, r = i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    if(r-l+1>=k){
                        if(find[l]) break;
                        ranges[l] = {l, r};
                        find[l] = true;
                        break;
                    }
                    l--;
                    r++;
                }
                else break;
            }
        }
        int res = 0;
        int i = 0;
        while(i<n){
            auto p = ranges[i];
            int l = p.first, r = p.second;
            if(l!=-1){
                res++;
                i = r+1;
            }
            else i++;
        }
        return res;
    }
};