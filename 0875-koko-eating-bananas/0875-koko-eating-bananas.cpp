class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int u = *max_element(piles.begin(), piles.end());
        int ans = u;

        while (l <= u) {
            int mid = l + (u - l) / 2;
            long long hours = 0;

            for (int pile : piles)
                hours += (pile + mid - 1) / mid;

            if (hours <= h) {
                ans = mid;
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};