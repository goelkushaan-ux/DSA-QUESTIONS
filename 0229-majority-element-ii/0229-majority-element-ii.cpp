class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int a = n / 3 + 1;
        vector<int> array;
        int c1 = 0, c2 = 0, e1 = INT_MIN, e2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (c1 == 0 && e2 != nums[i]) {
                e1 = nums[i];
                c1++;
            } else if (c2 == 0 && e1 != nums[i]) {
                e2 = nums[i];
                c2++;
            } else if (e1 == nums[i]) {
                c1++;
            } else if (e2 == nums[i]) {
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (e1 == nums[i])
                c1++;
            if (e2 == nums[i])
                c2++;
        }
        if (c1 >= a)
            array.push_back(e1);
        if (c2 >= a && e1 != e2)
            array.push_back(e2);
        return array;
    }
};