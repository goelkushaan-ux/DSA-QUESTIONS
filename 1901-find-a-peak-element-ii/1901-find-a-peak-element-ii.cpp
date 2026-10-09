class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();    // rows
        int n = mat[0].size(); // col
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int maxi = 0;

            for (int i = 1; i < m; i++)
                if (mat[i][mid] > mat[maxi][mid])
                    maxi = i;

            if (mid == 0 && n == 1)
                return {maxi, mid};

            if (mid == 0) {
                if (mat[maxi][mid] > mat[maxi][mid + 1])
                    return {maxi, mid};
                left = mid + 1;
            } else if (mid == n - 1) {
                if (mat[maxi][mid] > mat[maxi][mid - 1])
                    return {maxi, mid};
                right = mid - 1;
            } else if (mat[maxi][mid] > mat[maxi][mid - 1] &&
                       mat[maxi][mid] > mat[maxi][mid + 1]) {
                return {maxi, mid};
            } else if (mat[maxi][mid] < mat[maxi][mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return {-1, -1};
    }
};