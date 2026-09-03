class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1;
        int top;
        int i = 1;
        while (i < ratings.size()) {
            while (i < ratings.size() && ratings[i] == ratings[i - 1])
                ans++, i++;
            top = 1;
            while (i < ratings.size() && ratings[i] > ratings[i - 1]) {
                top++;
                ans += top;
                i++;
            }
            int bottom = 1;
            while (i < ratings.size() && ratings[i] < ratings[i - 1]) {
                ans += bottom;
                bottom++;
                i++;
            }
            if (bottom > top)
                ans = ans - top + bottom;
        }
        return ans;
    }
};