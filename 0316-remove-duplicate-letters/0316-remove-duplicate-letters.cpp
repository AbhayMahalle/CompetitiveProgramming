class Solution {
public:
    string removeDuplicateLetters(string str) {
        unordered_map<char, int> freq, taken;
        for(char &c : str) freq[c]++;
        string s = "";
        for(char &c : str){
            freq[c]--;
            if(!s.empty() && taken[c]==0 && s.back()>c && freq[s.back()]>0){
                while(!s.empty() && s.back()>c && freq[s.back()]>0){
                    cout << s.back() << " ";
                    taken[s.back()]--;
                    s.pop_back();
                }
                s.push_back(c);
                cout << s.back() << endl;
                taken[c]++;
            }
            else if(taken[c]==0){
                s.push_back(c);
                cout << s.back() << endl;
                taken[c]++;
            }
        }
        return s;
    }
};