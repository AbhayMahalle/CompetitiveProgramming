class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string paper = "", t = "";
        int prev = -1;
        int last = 0;
        int i = 0;
        for(char c = 'a'; c<='z'; c++){
            prev = last;
            i = last;
            char minChar = 'z';
            for(int j=i; j<n; j++) minChar = min(minChar, s[j]);
            if(i>=n) break;
            while(!t.empty() && t.back()<=c){
                paper.push_back(t.back());
                t.pop_back();
            }
            for(int j=i; j<n; j++){
                if(s[j]==c){
                    paper += c;
                    last = j+1;
                }
            }
            if(prev!=last){
                for(int j=prev; j<last; j++){
                    if(s[j]!=c) t += s[j];
                }
            }
            while(!t.empty() && t.back()<=minChar){
                paper.push_back(t.back());
                t.pop_back();
            }
        }
        while(!t.empty()){
            paper.push_back(t.back());
            t.pop_back();
        }
        return paper;
    }
};