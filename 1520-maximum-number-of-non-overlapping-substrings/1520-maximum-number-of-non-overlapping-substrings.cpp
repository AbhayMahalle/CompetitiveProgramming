class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        unordered_map<char, int> first, last;
        for(int i=0; i<n; i++){
            if(first.find(s[i])!=first.end()){
                last[s[i]] = i;
            }
            else {
                first[s[i]] = i;
                last[s[i]] = i;
            }
        }
        vector<string> res;
        vector<pair<int, int>> ranges;

        for(char c='a'; c<='z'; c++){
            if(first.find(c)!=first.end()){
                int l = first[c];
                int r = last[c];

                bool valid = true;

                // Dynamically expand r
                for(int i=l; i<=r; i++){
                    if(first[s[i]] < l){
                        valid = false;
                        break;
                    }
                    r = max(r, last[s[i]]);
                }

                if(valid){
                    ranges.push_back({r, l});
                }
            }
        }

        // Sort according to right endpoint
        sort(ranges.begin(), ranges.end());

        for(auto [r, l] : ranges){
            cout << l << " " << r << endl;
        }
        // Select maximum non-overlapping substrings
        int prevEnd = -1;
        for(auto [r, l] : ranges){
            if(l > prevEnd){
                res.push_back(s.substr(l, r-l+1));
                prevEnd = r;
            }
        }

        return res;
    }
};