#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ls(i, a, b) for(int i = a; i < b; i++)
#define le(i,a , b) for(int i = a; i <= b; i++)
#define gt(i, a, b) for(int i = a; i > b; i--)
#define ge(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back

const int N = 1e+4;
vector<int> graph[N];
bool vis[N];
vector<int> dfsResult;

void dfs(int vertex){
	dfsResult.pb(vertex);
	vis[vertex] = 1;
	for(auto child: graph[vertex]){
		if(vis[child]) continue;
		dfs(child);
	}
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		dfsResult.clear();
		le(i, 1, n + 1){
			graph[i].clear();
			vis[i] = 0;
		}
		le(i, 1, n){
			int x;
			cin >> x;
			if(x == 0) graph[i].pb(n + 1);
			else graph[n + 1].pb(i);
			if(i < n) graph[i].pb(i + 1);
		}
		dfs(1);
		if(dfsResult.size() == n + 1){
			for(auto& d: dfsResult){
				cout << d << " ";
			}
		}
		else cout << -1;
		cout << "\n";
	}
}