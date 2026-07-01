class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0;
        int n = s.size();
        int i = 0, j = 0;
        int res = 0;
        while(j<n){
            char ch = s[j];
            if(ch=='a') a++;
            else if(ch=='b') b++;
            else if(ch=='c') c++;
            while(a && b && c){
                ch = s[i];
                if(ch=='a') a--;
                else if(ch=='b') b--;
                else if(ch=='c') c--;
                res += 1 + (n-1-j);
                i++;
            }
            j++;
        }
        return res;

    }
};