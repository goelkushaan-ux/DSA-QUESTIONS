
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            int sum = 0, x = nums[i];
            while (x != 0) {
                sum += x % 10;
                x /= 10;
            }
            a.push_back({sum, nums[i]});
        }
        sort(a.begin(), a.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) 
            mp[a[i].second] = i;
        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || mp[nums[i]] == i)
                continue;
            int j = i, cycle = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = mp[nums[j]];
                cycle++;
            }
            ans += cycle - 1;
        }
        return ans;
    }
};
