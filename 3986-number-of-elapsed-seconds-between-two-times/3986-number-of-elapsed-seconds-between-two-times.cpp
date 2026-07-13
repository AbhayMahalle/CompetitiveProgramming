class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int res = 0;
        int t;
        string temp;
        temp = "";
        temp += endTime[0];
        temp += endTime[1];
        t = stoi(temp);
        res += t * 3600;
        temp = "";
        temp += endTime[3];
        temp += endTime[4];
        t = stoi(temp);
        res += t * 60;
        temp = "";
        temp += endTime[6];
        temp += endTime[7];
        t = stoi(temp);
        res += t;

        temp = "";
        temp += startTime[0];
        temp += startTime[1];
        t = stoi(temp);
        res -= t * 3600;
        temp = "";
        temp += startTime[3];
        temp += startTime[4];
        t = stoi(temp);
        res -= t * 60;
        temp = "";
        temp += startTime[6];
        temp += startTime[7];
        t = stoi(temp);
        res -= t;

        return res;
    }
};