struct DSU{
	int connected;
	vector<int> par, sz;
	void setup(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		for(int i = 0; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}
	int find(int u)
	{
		while(u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}
	int getsize(int u)
	{
		return sz[getPar(u)];
	}
	void merge(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);
		if(par1 == par2)
			return;
		connected--;
		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};
DSU dsu;
