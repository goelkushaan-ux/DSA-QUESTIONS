class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> a;
        a[0]=1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remove = sum - k;
            if (a.find(remove) != a.end())
                count+=a[remove];
            a[sum]++;
        }
        return count;
    }
};