class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x = 0, y = 0;
        int n = s1.size();
        int xy = 0, yx = 0;
        for(int i=0; i<n; i++){
            if(s1[i]=='x' && s2[i]=='y') {
                xy++;
            }
            else if(s1[i]=='y' && s2[i]=='x') {
                yx++;
            }
        }
        cout << xy << " " << yx << endl;
        int opr = 0;
        opr += xy/2 + yx/2;
        if(xy%2 && yx%2) opr += 2;
        else if(xy%2 || yx%2) return -1;
        return opr;
    }
};