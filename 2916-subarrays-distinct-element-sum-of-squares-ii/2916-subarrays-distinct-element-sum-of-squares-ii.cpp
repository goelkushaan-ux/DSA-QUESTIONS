class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> s1, s2, lz;

    void apply(int node, int len, long long x) {
        s2[node] =
            (s2[node] + 2 * x % MOD * s1[node] % MOD + x * x % MOD * len) % MOD;
        s1[node] = (s1[node] + x * len) % MOD;
        lz[node] += x;
    }

    void push(int node, int l, int r) {
        if (lz[node] == 0)
            return;
        int mid = (l + r) / 2;
        apply(2 * node, mid - l + 1, lz[node]);
        apply(2 * node + 1, r - mid, lz[node]);
        lz[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
        s1[node] = (s1[2 * node] + s1[2 * node + 1]) % MOD;
        s2[node] = (s2[2 * node] + s2[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s1.assign(4 * n, 0);
        s2.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        unordered_map<int, int> last; 
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int prev = last.count(nums[r]) ? last[nums[r]] : -1;
            update(1, 0, n - 1, prev + 1, r);
            last[nums[r]] = r;
            ans = (ans + s2[1]) % MOD;
        }
        return ans;
    }
};