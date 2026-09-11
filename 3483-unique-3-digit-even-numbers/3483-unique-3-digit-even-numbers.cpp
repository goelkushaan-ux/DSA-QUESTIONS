class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int arr[10] = {0};
        for (int x : digits)
            arr[x]++;
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            if (arr[i] == 0)
                continue;
            arr[i]--;
            for (int j = 0; j <= 9; j++) {
                if (arr[j] == 0)
                    continue;
                arr[j]--;
                for (int k = 0; k <= 8; k += 2)
                    if (arr[k] > 0)
                        ans++;
                arr[j]++;
            }
            arr[i]++;
        }
        return ans;
    }
};