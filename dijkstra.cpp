#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define inf 1e11+10

const ll N = 100009;
vector<pair<ll, ll>> graph[N+1]; // Weight is second element

void dijsktra(ll source, ll target){
	vector<ll> vis(N+1, 0);
	vector<ll> dis(N+1, inf);
	vector<ll> pred(N+1, -1);
	set<pair<ll, ll>> st; // Weight is first element

	st.insert({0, source});
	dis[source] = 0;
	while(st.size() > 0){
		auto node = *st.begin();
		ll v = node.second;
		ll dist = node.first;
		st.erase(st.begin());
		if(vis[v]) continue;
		vis[v] = 1;
		for(auto child: graph[v]){
			ll child_v = child.first;
			ll wt = child.second;
			if(dis[v] + wt < dis[child_v]){
				dis[child_v] = dis[v] + wt;
				pred[child_v] = v;
				st.insert({dis[child_v], child_v});
			}
		}
	}
	if(pred[target] == -1){ // Have also tried if(dis[target] == ing), if(!vis[target])
		cout << -1 << endl;
		return;
	}
	else{
		vector<ll> path;
		for(ll v = target; v != -1; v = pred[v]){
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		for(auto x: path) cout << x << " ";
		cout << "\n";
		return;
	}
}

int main(){
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		ll x, y, wt;
		cin >> x >> y >> wt;
		graph[x].push_back({y, wt});
		graph[y].push_back({x, wt});
	}
	dijsktra(1, n);
}