int n, m;
vi adj[N], dist(N), par(N);
bool vis[N];

void bfs(int s) {
    set(vis);  par.assign(n+1, -1);  dist.assign(n+1, MAX);

    par[s] = -1;  vis[s] = 1;  dist[s] = 0; 

    queue<int> q; q.push(s);

    while (q.size()) {
        int u = q.front();
        q.pop();
        // cout << u << endl;
        
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

}
