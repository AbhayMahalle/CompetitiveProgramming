class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> suffMatch(n, 0);
        int match = 0;
        int i = n-1, j = m-1;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                match++;
                j--;
            }
            suffMatch[i] = match;
            i--;
        }
        vector<int> seq;
        bool changePower = true;
        i = 0, j = 0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(changePower && i+1<n && suffMatch[i+1]>=(m-j-1)){
                seq.push_back(i);
                changePower = false;
                j++;
            }
            i++;
        }
        if(j>=m) return seq;
        return {};
    }
};