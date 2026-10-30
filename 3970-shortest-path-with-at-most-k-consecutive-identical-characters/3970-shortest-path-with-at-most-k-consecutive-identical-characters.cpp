class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges)
            adj[e[0]].push_back({e[1], e[2]});
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();
            if (cost != dist[u][cnt])
                continue;
            if (u == n - 1)
                return (int)cost;
            for (auto [v, w] : adj[u]) {
                int newcnt;
                if (labels[u] == labels[v])
                    newcnt = cnt + 1;
                else
                    newcnt = 1;
                if (newcnt > k)
                    continue;
                long long newCost = cost + w;
                if (newCost < dist[v][newcnt]) {
                    dist[v][newcnt] = newCost;
                    pq.push({newCost, v, newcnt});
                }
            }
        }
        return -1;
    }
};