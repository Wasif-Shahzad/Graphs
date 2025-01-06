#include <bits/stdc++.h>

using namespace std;
#define int int64_t

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(...)
#endif

void strongly_connected_components(const vector<vector<int>>& adj,
					vector<vector<int>>& components,
					vector<vector<int>>& adj_condensed){
	int n = adj.size();
	vector<bool> vis(n + 1, false);
	components.clear(); adj_condensed.clear();
	vector<int> order;
	auto dfs = [&] (int v, 
			const vector<vector<int>>& adj_trav, 
			vector<int>& output, auto&& dfs) -> void{
		vis[v] = 1;
		for(auto c: adj_trav[v]){
			if(vis[c]) continue;
			dfs(c, adj_trav, output, dfs);
		}
		output.push_back(v);
	};
	
	// topological sorting to get descending order of t[out] in linear time
	for(int i = 1; i < n; i++){
		if(!vis[i]){
			dfs(i, adj, order, dfs);
		}
	}
	reverse(order.begin(), order.end());

	// construction of reverse graph
	vector<vector<int>> adj_rev(n + 1);
	for(int i = 1; i < n; i++){
		for(auto v: adj[i]){
			adj_rev[v].push_back(i);
		}
	}

	vis.assign(n + 1, false);
	vector<int> roots(n + 1);

	for(int v: order){
		if(!vis[v]){
			// we dfs in reverse graph to get the SCC of node i
			vector<int> component;
			dfs(v, adj_rev, component, dfs);
			components.push_back(component);
			int root = *min_element(component.begin(), component.end());
			for(int u: component){
				roots[u] = root;
			}
		}
	}

	// now we build condensed graph out of roots
	adj_condensed.assign(n, {});
	for(int v = 1; v < n; v++){
		for(auto u: adj[v]){
			if(roots[u] != roots[v]){
				adj_condensed[roots[v]].push_back(roots[u]);
			}
		}
	}
}

int32_t main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
	#endif
	int n, m;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> graph(n + 1);
	vector<vector<int>> components;
	vector<vector<int>> graph_con(n + 1);
	cin >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	strongly_connected_components(graph, components, graph_con);
	dbg(components);
	const int MOD = 1e9 + 7;
	int ways = 1;
	int best = 0;
	for(auto component: components){
		int mn = 1e9 + 5;
		for(int u: component) mn = min(mn, a[u]);
		best += mn;
		int cnt = 0;
		for(int u: component)
			if(a[u] == mn)
				cnt++;
		ways = (ways * cnt) % MOD;
	}
	cout << best << " " << ways % MOD << '\n';
}
