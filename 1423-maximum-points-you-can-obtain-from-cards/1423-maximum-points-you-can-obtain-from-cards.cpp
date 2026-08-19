class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        for (int i = 0; i < k; i++)
            total += cardPoints[i];
        int maxi = total;
        for (int i = 0; i < k; i++) {
            total -= cardPoints[k - i - 1];
            total += cardPoints[cardPoints.size() - i - 1];
            maxi=max(maxi,total);
        }
        return maxi;
    }
};