class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        int m=nums1.size(),n=nums2.size();
        int i = m - 1, j = n - 1;
        for (int k = m + n - 1; k >= 0; k--) {
            if (i < 0)
            a.push_back(nums2[j--]);
            else if (j < 0)
                a.push_back(nums1[i--]);
            else if (nums1[i] > nums2[j])
                a.push_back(nums1[i--]);
            else
                a.push_back(nums2[j--]);
        }
        float median;
        if ((m+n) % 2 == 0)
            median = (a[(m+n) / 2 - 1] + a[(m+n) / 2]) / 2.0;
        else
            median = a[(m+n) / 2];

        return median;
    }
};