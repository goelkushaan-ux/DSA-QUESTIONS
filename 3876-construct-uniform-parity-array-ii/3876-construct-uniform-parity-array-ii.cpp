class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX, e = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 1)
                odd = min(odd, nums1[i]);
            else
                e = min(e, nums1[i]);
        }
        if (odd>e && odd<INT_MAX)
            return false;
        return true;
    }
};