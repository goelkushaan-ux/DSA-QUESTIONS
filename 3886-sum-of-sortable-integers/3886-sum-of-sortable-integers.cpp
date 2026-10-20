class Solution {
    bool isRotation(vector<int>& nums, vector<int>& s, int start, int k) {
        int drops = 0;
        int rotationStart = 0;
        for (int j = 0; j < k; j++) {
            int next = (j + 1) % k;
            if (nums[start + j] > nums[start + next]) {
                drops++;
                rotationStart = next;
                if (drops > 1)
                    return false;
            }
        }
        for (int j = 0; j < k; j++) {
            int idx = start + (rotationStart + j) % k;
            if (nums[idx] != s[start + j])
                return false;
        }
        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool possible = true;
            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sorted, start, k)) {
                    possible = false;
                    break;
                }
            }
            if (possible)
                ans += k;
        }
        return ans;
    }
};