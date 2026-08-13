class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int lar = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            map<int, string> even, odd;
            for (j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0)
                    even[nums[j]++];
                else
                    odd[nums[j]++];
                if (even.size() == odd.size())
                    lar = max(lar, j - i + 1);
            }
        }
        return lar;
    }
};