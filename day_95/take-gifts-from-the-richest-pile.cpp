class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        sort(gifts.begin(), gifts.end(), greater<int>());
        while (k--) {
            gifts[0] = sqrt(gifts[0]);
            sort(gifts.begin(), gifts.end(), greater<int>());
        }
        for (int i = 0; i < gifts.size(); i++) {
            sum += gifts[i];
        }
        return sum;
    }
};
