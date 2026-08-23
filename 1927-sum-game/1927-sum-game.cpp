class Solution {
public:
    bool sumGame(string num) {
        int firstHalf = 0;
        int secondHalf = 0;
        int n = num.size();
        int left = 0, right = 0;
        for(int i = 0; i<n; i++){
            char c = num[i];
            if(i<n/2) {
                if(c!='?') firstHalf += (c-'0');
                else left++;
            }
            else {
                if(c!='?') secondHalf += (c-'0');
                else right++;
            }
        }
        if((left+right)%2) return true;
        if(left>=right){
            left -= right;
            right = 0;
        }
        else{
            right -= left;
            left = 0;
        }
        if((left+right)%2) return true;
        cout << left << " " << right << endl;
        cout << firstHalf << " " << secondHalf;
        if(left==0){
            if(firstHalf<(secondHalf+(right/2)*9)) return true;
            else if(abs(firstHalf-secondHalf)>((right/2)*9)) return true;
        }
        else{
            if(secondHalf<(firstHalf+(left/2)*9)) return true;
            else if(abs(firstHalf-secondHalf)>((left/2)*9)) return true;
        }
        return false;
    }
};