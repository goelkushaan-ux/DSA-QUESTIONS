class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        long long r = accumulate(weights.begin(), weights.end(), 0);
        long long ans = r;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long count = 0, day = 0;
            for (int i = 0; i < weights.size(); i++) {
                count += weights[i];
                if (count > mid) {
                    day++;
                    count = weights[i];
                }
            }
            day++;
            if (day <= days) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};