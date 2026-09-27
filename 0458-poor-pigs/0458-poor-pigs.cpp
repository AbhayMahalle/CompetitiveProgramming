class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;

        int pigs = 0;
        int possibilities = 1;

        while (possibilities < buckets) {
            possibilities *= (rounds + 1);
            pigs++;
        }

        return pigs;
    }
};