class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char &c : s){
            freq[c-'a']++;
        }
        char mid;
        int m = -1;
        string str = "";
        char cur = 'a';
        for(int i=0; i<26; i++){
            if(freq[i]%2){
                m = 1;
                mid = 'a';
                mid += i;
            }
            int f = freq[i]/2;
            while(f--) str += char('a'+i);
            cur++;
        }
        string temp = str;
        reverse(temp.begin(), temp.end());
        if(m==1){
            str += mid;
        }
        str += temp;
        return str;
    }
};