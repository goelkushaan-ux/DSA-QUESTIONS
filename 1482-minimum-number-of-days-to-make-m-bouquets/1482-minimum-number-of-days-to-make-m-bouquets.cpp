class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n)
            return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = h;
        while (l <= h) {
            int mid = (l + h) / 2;
            int count = 0, b = 0;
            for (int i = 0; i < n; i++) {
                if (mid >= bloomDay[i])
                    count++;
                else {
                    b += count / k;
                    count = 0;
                }
            }
            b += count / k;
            if (b >= m) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};