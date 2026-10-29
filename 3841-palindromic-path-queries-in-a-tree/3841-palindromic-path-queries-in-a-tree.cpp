class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n, 0), tout(n, 0), base(n, 0), chars(n);
        for (int i = 0; i < n; i++) chars[i] = 1 << (s[i] - 'a');

        // iterative DFS from root 0
        int timer = 0;
        base[0] = chars[0];
        vector<array<int, 3>> st;
        st.push_back({0, -1, 0});
        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();
            if (state == 0) {
                tin[u] = timer++;
                st.push_back({u, p, 1});
                for (int w : adj[u]) {
                    if (w != p) {
                        depth[w] = depth[u] + 1;
                        up[0][w] = u;
                        base[w] = base[u] ^ chars[w];
                        st.push_back({w, u, 0});
                    }
                }
            } else {
                tout[u] = timer - 1;
            }
        }

        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int k = 0; k < LOG; k++)
                if (diff >> k & 1) a = up[k][a];
            if (a == b) return a;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][a] != up[k][b]) {
                    a = up[k][a];
                    b = up[k][b];
                }
            }
            return up[0][a];
        };

        // XOR Fenwick: range update, point query
        vector<int> bit(n + 2, 0);
        auto bitUpdate = [&](int i, int val) {
            for (i++; i <= n + 1; i += i & -i) bit[i] ^= val;
        };
        auto bitQuery = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & -i) res ^= bit[i];
            return res;
        };
        auto pathPrefix = [&](int x) { return base[x] ^ bitQuery(tin[x]); };

        vector<bool> res;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int m = 1 << (c - 'a');
                int delta = chars[u] ^ m;
                if (delta) {
                    chars[u] = m;
                    bitUpdate(tin[u], delta);
                    bitUpdate(tout[u] + 1, delta);
                }
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = pathPrefix(u) ^ pathPrefix(v) ^ chars[l];
                res.push_back((mask & (mask - 1)) == 0);
            }
        }
        return res;
    }
};