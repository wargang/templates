int n, m;
vpii adj[N];
vi dist(N);
vector<bool> vis(N);

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    dist.assign(n + 1, MAX);
    dist[src] = 0;
    
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        int v = t.ss, d = t.ff;
        if (vis[v]) continue;
        vis[v] = 1;
        for (auto i : adj[v]) {
            int vertex = i.ff, cost = i.ss;
            if (dist[vertex] > dist[v] + cost) {
                dist[vertex] = dist[v] + cost;
                pq.push({dist[vertex], vertex});
            }
        }
    }
}
